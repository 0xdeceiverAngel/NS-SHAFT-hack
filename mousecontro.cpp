#include <iostream>
#include <Windows.h>
using namespace std;
DWORD Ammo=0x19FD10;
DWORD pid,A;
int main(void)
{
	HWND h= ::FindWindow(NULL,"NS-SHAFT");
	RECT rect;
	GetWindowThreadProcessId(h,&pid);
	HANDLE p=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	cout<<h<<endl<<p<<endl;
	ReadProcessMemory(p,(LPVOID)Ammo,&A,sizeof(A),0);
	POINT pt;
	while(1){
	::GetWindowRect(h,&rect);
//	cout<<rect.bottom<<" "<<rect.left<<" "<<rect.right<<" "<<rect.top<<" \n";
	
	
//	cout << pt.x << "," << pt.y << endl; //顯示pt中的資料
	GetCursorPos(&pt);
	
//	cout<<pt.x-rect.left-40<<" "<<pt.x-rect.top-100<<endl;
	int x=pt.x-rect.left-40;
	int y=pt.y-rect.top-105;
//	ReadProcessMemory(p,(LPVOID)A+0x1158,&x,4,0);
//	ReadProcessMemory(p,(LPVOID)A+0x115c,&y,4,0);
	WriteProcessMemory(p,(LPVOID)A+0x115c,&y,sizeof(y),0);
	WriteProcessMemory(p,(LPVOID)A+0x1158,&x,sizeof(x),0);
//	cout<<x<<" "<<y; 
	
//	system("cls");
	}
//	

}
