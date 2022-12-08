#pragma once

#include "framework.h"
#include "HomeWorldRMDll.h"

//__declspec(naked) int HGodMode(ULONG_PTR) {};
EXPORT extern "C" __declspec(dllexport) void GodMode();
EXPORT extern "C" __declspec(dllexport) void NormalMode();