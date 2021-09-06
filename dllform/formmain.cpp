#include "formmain.h"
#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>  
using namespace dllform;
using namespace std;

void Main(void)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew formmain);
    Application::Exit();
}

int blood=1200;
int y=10;
int read_y;
DWORD base_addr=0x18FDA0,addr,pid;
HANDLE p;
HWND h;
RECT rect;
POINT pt;
int *adr;
int *adr2;
int *adr3;
string to_string(DWORD in)
{
	stringstream ss;
	ss << (int)in;
	string str = ss.str();
	return str;
};
void formmain::formmain_Load(System::Object^  sender, System::EventArgs^  e)
{
	p=GetCurrentProcess();
	h=FindWindow(NULL,L"NS-SHAFT");
	ReadProcessMemory(p,(LPVOID)base_addr,&addr,sizeof(addr),0);
	//string s=to_string(addr);
	//const char *c=s.c_str();
	//MessageBoxA(0,c ,"", MB_ICONINFORMATION);


	adr=(int* )0x18fd40;
	adr2=(int*)(*adr+0x8);
	adr3=(int*)(*adr2+0x12fc);


	this->timer_cursorpos->Start();
}
void formmain::timer_blood_Tick(System::Object^  sender, System::EventArgs^  e)
{
	ReadProcessMemory(p,(LPVOID)base_addr,&addr,sizeof(addr),0);
	WriteProcessMemory(p,(LPVOID)(addr+0x1170),&blood,sizeof(blood),0);
}

void formmain::timer_fallen_Tick(System::Object^  sender, System::EventArgs^  e)
{
	ReadProcessMemory(p,(LPVOID)(addr+0x115c),&read_y,sizeof(y),0);
	if(read_y>340)
	{
		WriteProcessMemory(p,(LPVOID)(addr+0x115c),&y,sizeof(blood),0);
	}
}
void formmain::timer_cursorpos_Tick(System::Object^  sender, System::EventArgs^  e)
{
	
	GetCursorPos(&pt);
	
	
	GetWindowRect(h,&rect);
	int cur_x=0;
	int cur_y=0;


	ReadProcessMemory(p,(LPVOID)(addr+0x1158),&cur_x,4,0);
	ReadProcessMemory(p,(LPVOID)(addr+0x115c),&cur_y,4,0);


	this->label_x->Text=gcnew String((to_string((DWORD)cur_x)).c_str());
	this->label_y->Text=gcnew String((to_string((DWORD)cur_y)).c_str());

	this->label_level->Text=gcnew String((to_string((DWORD)*adr3)).c_str());

	
//	string s=to_string((DWORD)*adr3);
//	const char *c=s.c_str();

	if(this-> cursor_ckb->Checked)
	{
		int cur_x=pt.x-rect.left-40;
		int cur_y=pt.y-rect.top-105;
		WriteProcessMemory(p,(LPVOID)(addr+0x115c),&cur_y,sizeof(cur_x),0);
		WriteProcessMemory(p,(LPVOID)(addr+0x1158),&cur_x,sizeof(cur_y),0);
	}
}
void formmain::blood_ckb_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{

    if (this->blood_ckb->Checked)
    {
       this->timer_blood->Start();
    }
    else
    {
       this->timer_blood->Stop();
    }
}
void formmain::non_fallen_ckb_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{

    if (this->non_fallen_ckb->Checked)
    {
       this->timer_fallen->Start();
    }
    else
    {
       this->timer_fallen->Stop();
    }
}

//void formmain::button1_Click(System::Object^  sender, System::EventArgs^  e)
//{
//	int *adr=(int* )0x18fd40;
//	int *adr2=(int*)(*adr+0x8);
//	int *adr3=(int*)(*adr2+0x12fc);
//	string s=to_string((DWORD)*adr3);
//	const char *c=s.c_str();
//	MessageBoxA(0,c ,"", MB_ICONINFORMATION);
//}
