// ���W���[������G�N�X�|�[�g����Ă���֐��Q Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "ExportedFunctionsFromModule.h"
#include "ExportedFunction.h"
#include <algorithm>

std::vector<ExportedFunction> ExportedFunctionsFromModule(const IMAGE_DOS_HEADER& imageDosHeader)
{
	std::vector<ExportedFunction> retval;
	const auto& d = *PIMAGE_EXPORT_DIRECTORY(&LPCSTR(&imageDosHeader)[PIMAGE_NT_HEADERS(&LPCSTR(&imageDosHeader)[imageDosHeader.e_lfanew])->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress]);
	const auto AddressOfFunctions = reinterpret_cast<const DWORD*>(&LPCSTR(&imageDosHeader)[d.AddressOfFunctions]);
	const auto AddressOfNames     = reinterpret_cast<const DWORD*>(&LPCSTR(&imageDosHeader)[d.AddressOfNames    ]);
	retval.reserve(d.NumberOfNames);
	for (DWORD i = 0; i < d.NumberOfNames; ++i) {
		retval.push_back(
		{ &LPCSTR(&imageDosHeader)[AddressOfFunctions[i]]
		, &LPCSTR(&imageDosHeader)[AddressOfNames    [i]]
		});
	}
	std::sort(retval.begin(), retval.end(), [](const ExportedFunction& lhs, const ExportedFunction& rhs) { return lhs.Name() < rhs.Name(); });
	return retval;
}