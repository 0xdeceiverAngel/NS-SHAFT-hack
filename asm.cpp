#include <iostream>
#include <windows.h>
using namespace std;
DWORD pid;

BYTE spink[]={0x83,0xAC,0x08,0x70,0x11,0x00,0x00,0x00}; 
//WriteProcessMemory(hProcess, lpBaseAddress, yourBytes, sizeof(yourBytes), NULL);
DWORD spinkplatform=0x406991;
DWORD spinkabove=0x406311;
DWORD springplatform=0x40661E;

int main() {
	HWND h= ::FindWindow(NULL,"NS-SHAFT");
	GetWindowThreadProcessId(h,&pid);
	HANDLE p=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	cout<<h<<endl<<p<<endl;
	WriteProcessMemory(p, (LPVOID)spinkplatform, spink, sizeof(spink), NULL);
	WriteProcessMemory(p, (LPVOID)springplatform, spink, sizeof(spink), NULL);
	WriteProcessMemory(p, (LPVOID)spinkabove, spink, sizeof(spink), NULL);
	 }
