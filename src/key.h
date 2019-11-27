//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#pragma once

class ckey
{
public:

	int id;
	char button;
	int pitch;
	int yaw;
	int setnum = 0;

	ckey(int s ,int i, char a, int b, int c) {
		setnum = s;
		id = i;
		button = a;
		pitch = b;
		yaw = c;
	}

	void click();
	void onTick();

	bool once = false;
 
};