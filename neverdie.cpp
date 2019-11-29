#include <iostream>
#include <windows.h>
using namespace std;
DWORD pid,A;
//DWORD Ammo=0x19FCFC;
DWORD Ammo=0x19FD10;
int y=10;
int a;
int read_y;
int b=10;
int main() {
	HWND h= ::FindWindow(NULL,"NS-SHAFT");
	GetWindowThreadProcessId(h,&pid);
	HANDLE p=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	cout<<h<<endl<<p<<endl;
	ReadProcessMemory(p,(LPVOID)Ammo,&A,sizeof(A),0);
	cout<<A<<endl;
    cout<<hex<<A<<endl;
	cout<<(LPVOID)A+0x1170;
    ReadProcessMemory(p,(LPVOID)A+0x1170,&a,sizeof(a),0);
	   while(1)
	   {
	 //  cout<<dec<<a<<endl;
		ReadProcessMemory(p,(LPVOID)A+0x115c,&read_y,sizeof(y),0);
	   	ReadProcessMemory(p,(LPVOID)A+0x1170,&a,sizeof(a),0);
	   		if(read_y>340)
	   		{
	   			WriteProcessMemory(p,(LPVOID)A+0x115c,&y,sizeof(b),0);
			}
	 		if(a<4)
	 		{
	 			WriteProcessMemory(p,(LPVOID)A+0x1170,&b,sizeof(b),0);
			 }

		}
	 }
