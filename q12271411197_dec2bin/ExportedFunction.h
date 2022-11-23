// モジュールからエクスポートされている関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <string>
class ExportedFunction {
	LPCVOID     pvAddress   ;
	LPCSTR      pszName     ;
	bool        isCpp       ;
	std::string display_name;
	static std::string CppDisplayName(LPCSTR first);
public:
	ExportedFunction
	( _In_ LPCVOID pvAddress  
	, _In_ LPCSTR  pszName    
	);
	bool IsCpp() const noexcept;
	const std::string& Name() const noexcept;
	FARPROC Address() const noexcept;
};
