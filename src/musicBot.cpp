//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#include "musicBot.h"

HWND hwnd;

void setHwnd(HWND h) {
	hwnd = h;
}

HWND getHwnd()
{
	return 	hwnd;
}

std::vector<ckeyclickmsg> keyclickmsgs;

void clearmsgs() {
	keyclickmsgs.clear();
}

vector<ckeyclickmsg> getmsgs() {
	return keyclickmsgs;
}

 void push_msg(ckeyclickmsg msg)
{
	keyclickmsgs.push_back(msg);
}