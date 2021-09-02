#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main() {

	DWORD dwProcess;
	DWORD procID;
	
	char dll[]="41.dll";
	char myDLL[MAX_PATH];

	GetFullPathNameA(dll, MAX_PATH, myDLL, NULL);
	cout<<myDLL<<endl;

	
	HWND hwnd = FindWindowA(NULL, "NS-SHAFT"); 
	GetWindowThreadProcessId(hwnd, &procID);
	
	
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, procID);
	cout<<GetLastError()<<endl;
	
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	cout<<GetLastError()<<endl;
	cout<<hProcess<<endl<<allocatedMem<<endl;
	
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	cout<<GetLastError()<<endl;
	
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	cout<<GetLastError()<<endl;
	
	CloseHandle(hProcess);
	cout<<GetLastError()<<endl;
	cin>> dll;

}
