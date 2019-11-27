//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#include "musicBot.h"
#include "key.h"

void ckey::onTick()
{ 
	if (KEY_DOWN(button)) {
		if (!once) {
			if (KEY_DOWN(18)) {
				for (int i=0;i<setnum;i++)
				{
					SendMessage(getHwnd(), WM_RBUTTONDOWN, 0, 0);
					Sleep(1);
					SendMessage(getHwnd(), WM_RBUTTONUP, 0, 0);
					Sleep(50);
				}
			}
			else {
 
				click();
			}
			once = true;
		}
	}
	else {
		once = false;
	} 
}	

void ckey::click()
{

	ckeyclickmsg msg;
	msg.yaw = yaw;
	msg.pitch = pitch;
	push_msg(msg); 
}