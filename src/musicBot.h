//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#pragma once
#include "math.h"
#include <time.h>  
#include "windows.h"
#include "stdio.h"
#include "key.h"
#include <vector>

using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

class ckeyclickmsg
{
public:
	int pitch;
	int yaw;
};

extern void setHwnd(HWND h);
extern HWND getHwnd();

extern void clearmsgs();
extern vector<ckeyclickmsg> getmsgs();
extern void push_msg(ckeyclickmsg msg);


static int pitch = 0;
static int yaw = 0;
 
static void setRotaton( int p,int y)
{
	int offset_p = pitch - p;
	int offset_y = yaw - y;

	pitch = p;
	yaw = y;

	RECT rect;
	GetClientRect(getHwnd(), &rect);
	
	SendMessage(getHwnd(), WM_MOUSEMOVE, 0, MAKELPARAM((rect.right / 2) + offset_p, (rect.bottom / 2) + offset_y));
 
}

 
