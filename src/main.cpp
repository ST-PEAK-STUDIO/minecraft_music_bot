//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#include "windows.h"
#include "stdio.h"
#include "musicBot.h"
#include "key.h"
#include "play.h"

#include <vector>

using namespace std;

bool f8_down = false;
bool f9_down = false;

void main()
{
	setHwnd(FindWindow(NULL, "Minecraft 1.12"));

	vector<ckey*> keys;

	keys.push_back(new ckey(1,0, 'Z', 420,50));
	keys.push_back(new ckey(1+2,1, 'X', 350, 35));
	keys.push_back(new ckey(1+4,2, 'C', 220, 25));

	keys.push_back(new ckey(1+5,3, 'V', 0, 0));

	keys.push_back(new ckey(1+7,4, 'B', -220, 25));
	keys.push_back(new ckey(1+9,5, 'N', -350, 35));
	keys.push_back(new ckey(1+11,6, 'M', -420, 50));

	keys.push_back(new ckey(13,7, VK_NUMPAD1, 340, 150));
	keys.push_back(new ckey(13+2,8, VK_NUMPAD2, 250, 170));
	keys.push_back(new ckey(13+4,9, VK_NUMPAD3, 150, 170));

	keys.push_back(new ckey(13+5,10, VK_NUMPAD4, 0, 170));

	keys.push_back(new ckey(13+7,11, VK_NUMPAD5, -150, 170));
	keys.push_back(new ckey(13+9,12, VK_NUMPAD6, -250, 170));
	keys.push_back(new ckey(13+11,13, VK_NUMPAD7, -340, 150));

	cplay* play = new cplay();
	play->keys = keys;

	//hypixel密室杀手大厅那个,最后一个需要为true (升高了一个半音)
	play->load("c_a.mid",0.002f,false);

	while (true)
	{  
		if (KEY_DOWN(VK_F8)) {
			if (!f8_down) {
				if (!play->start) {
					printf("开始播放 \n");
					play->play();
				}
				else {
					printf("暂停 \n");
					play->pause();
				}
				f8_down = true;
			}
		}
		else {
			f8_down = false;
		}
 
		if (KEY_DOWN(VK_F9)) {
			if (!f9_down) {
				printf("已重置 \n");
				play->reset();
				f9_down = true;
			}
		}
		else {
			f9_down = false;
		}


		play->onTick();
		for (unsigned int i = 0; i < keys.size(); i++) {
			keys[i]->onTick();
		}

		for (unsigned int i = 0; i <getmsgs().size(); i++) {

			setRotaton(getmsgs()[i].pitch, getmsgs()[i].yaw);
			Sleep(1);
			SendMessage(getHwnd(), WM_LBUTTONDOWN, 0, 0);
			Sleep(1);
			SendMessage(getHwnd(), WM_LBUTTONUP, 0, 0);
			if (play->start) {
				keybd_event(VK_LSHIFT, 0, 0, 0);
				Sleep(40);
				keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
			}
			else {
				Sleep(40);
			}
		}
		clearmsgs();

	}
}