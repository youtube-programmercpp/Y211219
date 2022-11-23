// モジュールからエクスポートされている関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "ExportedFunction.h"
std::string ExportedFunction::CppDisplayName(LPCSTR first)
{
	return std::string(first, strchr(first, '@') - first);
}

ExportedFunction::ExportedFunction
( _In_ LPCVOID pvAddress  
, _In_ LPCSTR  pszName    
)
	: /*LPCVOID    */pvAddress   { pvAddress }
	, /*LPCSTR     */pszName     { pszName   }
	, /*bool       */isCpp       { *pszName == '?' }
	, /*std::string*/display_name{ isCpp ? CppDisplayName (&pszName[1]) : pszName }
{
}
bool ExportedFunction::IsCpp() const noexcept
{
	return isCpp;
}
const std::string& ExportedFunction::Name() const noexcept
{
	return display_name;
}
FARPROC ExportedFunction::Address() const noexcept
{
	return FARPROC(pvAddress);
}
