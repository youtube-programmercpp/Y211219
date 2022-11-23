// プログラム制御ダイアログボックス Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "DialogBox_ProgramController.h"
#include "ExportedFunctionsFromModule.h"
#include "ExportedFunction.h"
#include "Thread_ProgramExecution.h"
#include "ExtendedWindowMessage.h"
#include "resource.h"
#include <iostream>
#include <sstream>
#include <CommCtrl.h>
extern "C" extern const IMAGE_DOS_HEADER __ImageBase;

INT_PTR DialogBox_ProgramController::Handle_WM_INITDIALOG(HWND hDlg) noexcept
{
	programs = ExportedFunctionsFromModule(__ImageBase);
	const auto hListView = GetDlgItem(hDlg, IDC_LIST_Programs);
	ListView_SetExtendedListViewStyleEx(hListView, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
	LVCOLUMN col = {};
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	col.pszText = const_cast<LPTSTR>(TEXT("Program"));
	col.cx = 240;
	ListView_InsertColumn(hListView, 0, &col);
	col.pszText = const_cast<LPTSTR>(TEXT("Language"));
	col.cx = 60;
	ListView_InsertColumn(hListView, 1, &col);
	col.pszText = const_cast<LPTSTR>(TEXT("State"));
	col.cx = 80;
	ListView_InsertColumn(hListView, 2, &col);

	LVITEMA m = {};
	for (const auto& r : programs) {
		m.mask     = LVIF_TEXT | LVIF_PARAM;
		m.pszText  = const_cast<LPSTR>(r.Name().c_str());
		m.lParam   = LPARAM(&r);
		m.iItem    = INT_MAX;
		m.iSubItem = 0;
		m.iItem    = static_cast<int>(SendMessageA(hListView, LVM_INSERTITEMA, 0, LPARAM(&m)));
		m.mask     = LVIF_TEXT;
		m.pszText  = const_cast<LPSTR>(r.IsCpp() ? "C++" : "C");
		m.iSubItem = 1;
		SendMessageA(hListView, LVM_SETITEMA, 0, LPARAM(&m));
	}
	UpdateUI(hDlg, false);
	return true;
}
void DialogBox_ProgramController::UpdateUI(HWND hDlg, bool thread_running) noexcept
{
	EnableWindow(GetDlgItem(hDlg, IDOK                        ), !thread_running);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON_CtrlZ_Enter      ),  thread_running);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON_INT_MAX_PLUS_ONE ),  thread_running);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON_UINT_MAX_PLUS_ONE),  thread_running);
}
void DialogBox_ProgramController::OnThreadEnter(HWND hDlg, WPARAM wParam, LPARAM lParam) noexcept
{
	Thread_ProgramExecution::ListViewSetItemState(GetDlgItem(hDlg, IDC_LIST_Programs), lParam, TEXT("Running"));
	UpdateUI(hDlg, true);
}
void DialogBox_ProgramController::OnThreadLeave(HWND hDlg, WPARAM wParam, LPARAM lParam) noexcept
{
	(void)WaitForSingleObject(HANDLE(wParam), INFINITE);
	(void)CloseHandle(HANDLE(wParam));
	Thread_ProgramExecution::ListViewSetItemState(GetDlgItem(hDlg, IDC_LIST_Programs), lParam, TEXT(""));
	UpdateUI(hDlg, false);
	SetForegroundWindow(hDlg);
}
void DialogBox_ProgramController::ExecuteProgram(HWND hDlg, HWND hListView, int iItem) noexcept
{
	LVITEM m = {};
	m.iItem = iItem;
	m.mask = LVIF_PARAM;
	ListView_GetItem(hListView, &m);
	const auto pThread = new Thread_ProgramExecution
	{ /*_In_ DialogBox_ProgramController * pDialogData */this
	, /*_In_ ExportedFunction            * pProgramData*/reinterpret_cast<ExportedFunction*>(m.lParam)
	, /*_In_ HWND                          hDlg        */hDlg
	};
	if (!pThread->Start([](void* pvThread) noexcept->unsigned
	{
#define pThread static_cast<Thread_ProgramExecution*>(pvThread)
		pThread->PostMessageW(UINT(ExtendedWindowMessage::THREAD_ENTERED));
		SetForegroundWindow(GetConsoleWindow());
		const auto retval = (*pThread)();
		std::cin.clear();
		pThread->PostMessageW(UINT(ExtendedWindowMessage::THREAD_LEAVING));
		delete pThread;
#undef  pThread
		return retval;
	}))
		delete pThread;
}
void DialogBox_ProgramController::Handle_WM_COMMAND_IDOK(HWND hDlg) noexcept
{
	const auto hListView = GetDlgItem(hDlg, IDC_LIST_Programs);
	const auto iItem = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
	if (iItem != -1) {
		ExecuteProgram(hDlg, hListView, iItem);
	}
}
INPUT DialogBox_ProgramController::MakeInputKeyDown(WORD wVk)
{
	INPUT retval{ INPUT_KEYBOARD };
	retval.ki = 
		{ /*WORD    wVk    ;*/wVk
		};
	return retval;
}
INPUT DialogBox_ProgramController::MakeInputKeyUp(WORD wVk)
{
	INPUT retval{ INPUT_KEYBOARD };
	retval.ki = 
		{ /*WORD    wVk    ;*/wVk
		, /*WORD    wScan  ;*/0
		, /*DWORD   dwFlags;*/KEYEVENTF_KEYUP
		};
	return retval;
}
void DialogBox_ProgramController::SendStringToConsole(LPCSTR pszTextA)
{
	std::vector<INPUT> a;
	for (; *pszTextA;++pszTextA) {
		a.push_back(MakeInputKeyDown(static_cast<BYTE>(*pszTextA)));
		a.push_back(MakeInputKeyUp  (static_cast<BYTE>(*pszTextA)));
	}
	a.push_back(MakeInputKeyDown(VK_RETURN));
	a.push_back(MakeInputKeyUp  (VK_RETURN));
	SetForegroundWindow(GetConsoleWindow());
	SendInput(static_cast<UINT>(a.size()), &a.front(), sizeof (decltype(a)::value_type));
}
INT_PTR DialogBox_ProgramController::Handle_WM_COMMAND_IDC_BUTTON_INT_MAX    (HWND hDlg)
{
	SendStringToConsole((std::ostringstream() << INT_MAX + 1LL).str().c_str());
	return true;
}
INT_PTR DialogBox_ProgramController::Handle_WM_COMMAND_IDC_BUTTON_UINT_MAX   (HWND hDlg)
{
	SendStringToConsole((std::ostringstream() << UINT_MAX + 1ULL).str().c_str());
	return true;
}
INT_PTR DialogBox_ProgramController::Handle_WM_COMMAND_IDC_BUTTON_CtrlZ_Enter(HWND hDlg)
{
	std::vector<INPUT> a;
	a.push_back(MakeInputKeyDown(VK_CONTROL));
	a.push_back(MakeInputKeyDown('Z'));
	a.push_back(MakeInputKeyUp  ('Z'));
	a.push_back(MakeInputKeyUp  (VK_CONTROL));
	a.push_back(MakeInputKeyDown(VK_RETURN));
	a.push_back(MakeInputKeyUp  (VK_RETURN));
	SetForegroundWindow(GetConsoleWindow());
	SendInput(static_cast<UINT>(a.size()), &a.front(), sizeof (decltype(a)::value_type));
	return true;
}
INT_PTR DialogBox_ProgramController::HandleMessage(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept
{
	switch (message) {
	case UINT(ExtendedWindowMessage::THREAD_ENTERED): OnThreadEnter(hDlg, wParam, lParam); return true;
	case UINT(ExtendedWindowMessage::THREAD_LEAVING): OnThreadLeave(hDlg, wParam, lParam); return true;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON_INT_MAX_PLUS_ONE    : return Handle_WM_COMMAND_IDC_BUTTON_INT_MAX    (hDlg);
		case IDC_BUTTON_UINT_MAX_PLUS_ONE   : return Handle_WM_COMMAND_IDC_BUTTON_UINT_MAX   (hDlg);
		case IDC_BUTTON_CtrlZ_Enter: return Handle_WM_COMMAND_IDC_BUTTON_CtrlZ_Enter(hDlg);
		case IDOK:
			Handle_WM_COMMAND_IDOK(hDlg);
			return true;
		case IDCANCEL:
			EndDialog(hDlg, IDOK);
			return true;
		default:
			return false;
		}
	case WM_NOTIFY:
		switch (wParam) {
		case IDC_LIST_Programs:
			switch (LPNMHDR(lParam)->code) {
			case NM_DBLCLK:
				{
					const auto iItem = LPNMITEMACTIVATE(lParam)->iItem;
					if (iItem != -1)
						ExecuteProgram(hDlg, LPNMHDR(lParam)->hwndFrom, iItem);
				}
				return true;
			default:
				return false;
			}
		default:
			return false;
		}
	default:
		return false;
	}
}
DialogBox_ProgramController::DialogBox_ProgramController() noexcept
{
}
DialogBox_ProgramController::~DialogBox_ProgramController()
{
}
INT_PTR DialogBox_ProgramController::DialogBoxParamW(_In_opt_ HWND hWndParent) noexcept
{
	return ::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */HINSTANCE(&__ImageBase)
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_ProgramController)
	, /*_In_opt_ HWND      hWndParent    */hWndParent
	, /*_In_opt_ DLGPROC   lpDialogFunc  */[](HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept->INT_PTR
		{
			if (const auto pThis = reinterpret_cast<DialogBox_ProgramController*>(GetWindowLongPtrW(hDlg, DWLP_USER)))
				return pThis->HandleMessage(hDlg, message, wParam, lParam);
			else if (message == WM_INITDIALOG) {
				SetWindowLongPtrW(hDlg, DWLP_USER, lParam);
				return reinterpret_cast<DialogBox_ProgramController*>(lParam)->Handle_WM_INITDIALOG(hDlg);
			}
			else
				return false;
		}
	, /*_In_     LPARAM    dwInitParam   */LPARAM(this)
	);
}
