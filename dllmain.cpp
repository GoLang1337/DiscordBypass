#include "pch.h"
std::ofstream logs;

typedef BYTE* _BYTE;
typedef DWORD _DWORD;

typedef __int64(__fastcall* t_188B0)();
t_188B0 hook_188B0 = (t_188B0)((uintptr_t)GetModuleHandle(L"discord.dll") + 0x188B0);

__int64 sub_188B0() {
    HANDLE v4; // rax
    LPCWSTR v25; // [rsp+50h] [rbp-2B8h] BYREF

    v25 = L"\\\\.\\pipe\\discord-ipc-%d";
    v4 = CreateFileW(v25, 0xC0000000, 0, 0i64, 3u, 0, 0i64);
    return CloseHandle(v4);
}

DWORD WINAPI MainThread(HMODULE hModule)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID&)hook_188B0, &sub_188B0);
    DetourTransactionCommit();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, NULL));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}