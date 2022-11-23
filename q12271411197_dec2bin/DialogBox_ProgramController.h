// プログラム制御ダイアログボックス Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <vector>
class ExportedFunction;
class DialogBox_ProgramController {
	std::vector<ExportedFunction> programs;

	INT_PTR Handle_WM_INITDIALOG(HWND hDlg) noexcept;
	void UpdateUI(HWND hDlg, bool thread_running) noexcept;
	void OnThreadEnter(HWND hDlg, WPARAM wParam, LPARAM lParam) noexcept;
	void OnThreadLeave(HWND hDlg, WPARAM wParam, LPARAM lParam) noexcept;
	void ExecuteProgram(HWND hDlg, HWND hListView, int iItem) noexcept;
	void Handle_WM_COMMAND_IDOK(HWND hDlg) noexcept;
	static INPUT MakeInputKeyDown(WORD wVk);
	static INPUT MakeInputKeyUp(WORD wVk);
	static void SendStringToConsole(LPCSTR pszTextA);
	INT_PTR Handle_WM_COMMAND_IDC_BUTTON_INT_MAX    (HWND hDlg);
	INT_PTR Handle_WM_COMMAND_IDC_BUTTON_UINT_MAX   (HWND hDlg);
	INT_PTR Handle_WM_COMMAND_IDC_BUTTON_CtrlZ_Enter(HWND hDlg);
	INT_PTR HandleMessage(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept;
public:
	DialogBox_ProgramController() noexcept;
	~DialogBox_ProgramController();
	INT_PTR DialogBoxParamW(_In_opt_ HWND hWndParent) noexcept;
};
