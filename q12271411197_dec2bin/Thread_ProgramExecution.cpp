// プログラム実行スレッド Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "Thread_ProgramExecution.h"
#include "ExtendedWindowMessage.h"
#include "DialogBox_ProgramController.h"
#include "ExportedFunction.h"
#include <process.h>
#include <CommCtrl.h>
#include <iostream>
#include <sstream>

Thread_ProgramExecution::Thread_ProgramExecution
( _In_ DialogBox_ProgramController * pDialogData 
, _In_ ExportedFunction            * pProgramData
, _In_ HWND                          hDlg        
) noexcept
	: /*DialogBox_ProgramController * */pDialogData { pDialogData  }
	, /*ExportedFunction            * */pProgramData{ pProgramData }
	, /*HWND                          */hDlg        { hDlg         }
	, /*HANDLE                        */hThread     {              }
{
}
bool Thread_ProgramExecution::Start(_In_ _beginthreadex_proc_type _StartAddress) noexcept
{
	if (const auto hThread = HANDLE(_beginthreadex
	( /*_In_opt_  void*                    _Security    */nullptr
	, /*_In_      unsigned                 _StackSize   */0
	, /*_In_      _beginthreadex_proc_type _StartAddress*/_StartAddress
	, /*_In_opt_  void*                    _ArgList     */this
	, /*_In_      unsigned                 _InitFlag    */CREATE_SUSPENDED
	, /*_Out_opt_ unsigned*                _ThrdAddr    */nullptr
	))) {
		(void)ResumeThread(this->hThread = hThread);
		return true;
	}
	else
		return false;
}
BOOL Thread_ProgramExecution::PostMessageW(UINT Msg) noexcept
{
	return ::PostMessageW(hDlg, Msg, WPARAM(hThread), LPARAM(pProgramData));
}
unsigned Thread_ProgramExecution::operator()() noexcept
{
	const auto program = (std::ostringstream() << pProgramData->Name() << (pProgramData->IsCpp() ? "[C++]" : "[C言語]")).str();
	std::cout << program << " ... 開始します。\n";
	const auto retval = static_cast<unsigned>((*FARPROC(pProgramData->Address()))());
	std::cout << program << " ... 終了しました。\n";
	return retval;
}
void Thread_ProgramExecution::ListViewSetItemState(HWND hListView, LPARAM lParam, LPCTSTR pszText)
{
	const LVFINDINFO f =
	{ /*UINT    flags      ;*/LVFI_PARAM
	, /*LPCTSTR psz        ;*/nullptr
	, /*LPARAM  lParam     ;*/lParam
	, /*POINT   pt         ;*/{}
	, /*UINT    vkDirection;*/0
	};
	LVITEM m = {};
	m.iItem    = ListView_FindItem(hListView, -1, &f);
	m.iSubItem = 2;
	m.mask     = LVIF_TEXT;
	m.pszText  = const_cast<LPTSTR>(pszText);
	ListView_SetItem(hListView, &m);
}
