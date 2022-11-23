// テスト実行メイン関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "DialogBox_ProgramController.h"
#include <Windows.h>
#include <CommCtrl.h>
#pragma comment(lib, "comctl32")
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#undef main
int main()
{
	InitCommonControls();
	DialogBox_ProgramController{}.DialogBoxParamW(nullptr);
}
