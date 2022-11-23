// モジュールからエクスポートされている関数群 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <vector>
class ExportedFunction;
std::vector<ExportedFunction> ExportedFunctionsFromModule(const IMAGE_DOS_HEADER& imageDosHeader);
