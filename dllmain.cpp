#include "stdafx.h"

DWORD WINAPI MainThread(LPVOID parm)
{
	int blood=10;
	int y=10;
	int read_y;
	DWORD base_addr=0x18FDA0,addr;

	HANDLE p=GetCurrentProcess();
	MessageBox(0, L"main thread", L"", MB_ICONINFORMATION);
	while(1)
	{
		ReadProcessMemory(p,(LPVOID)base_addr,&addr,sizeof(addr),0);
		WriteProcessMemory(p,(LPVOID)(A+0x1170),&blood,sizeof(blood),0);

		ReadProcessMemory(p,(LPVOID)(A+0x115c),&read_y,sizeof(y),0);
	   		if(read_y>340)
	   		{
	   			WriteProcessMemory(p,(LPVOID)(A+0x115c),&y,sizeof(blood),0);
			}
		
	}


}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBox(0, L"Hello From testlib!", L"", MB_ICONINFORMATION);
		CreateThread(0,0,MainThread,hModule,0,0);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

