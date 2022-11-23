// プログラム実行スレッド Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <process.h>
class DialogBox_ProgramController;
class ExportedFunction;
class Thread_ProgramExecution {
	DialogBox_ProgramController * pDialogData ;
	ExportedFunction            * pProgramData;
	HWND                          hDlg        ;
	HANDLE                        hThread     ;
public:
	Thread_ProgramExecution
	( _In_ DialogBox_ProgramController * pDialogData 
	, _In_ ExportedFunction            * pProgramData
	, _In_ HWND                          hDlg        
	) noexcept;
	bool Start(_In_ _beginthreadex_proc_type _StartAddress) noexcept;
	BOOL PostMessageW(_In_ UINT Msg) noexcept;
	unsigned operator()() noexcept;
	static void ListViewSetItemState(HWND hListView, LPARAM lParam, LPCTSTR pszText);
};
