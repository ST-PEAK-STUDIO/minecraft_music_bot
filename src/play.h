//***********************************************
//programmer:  baiqifeng<saintpeakstudio@gmail.com>
//lastedit: 2019/11/27
//***********************************************

#pragma once
#include "MidiFile.h"
#include "key.h"
#include <vector>

using namespace std;
using namespace smf;

class note {
public:

	int key;
	int command;
	float pos;
	bool isplay = false;
};

class cplay
{
public:

	vector<ckey*> keys;

	int castkey(int in,bool offsetOne)
	{
		if (offsetOne)
		{
			switch (in)
			{
			//case 48:return 0;
			case 50:return 0;
			case 52:return 1;
			case 53:return 2;
			case 55:return 3;
			case 57:return 4;
			case 59:return 5;
			case 60:return 6;

			case 62:return 7;
			case 64:return 8;
			case 65:return 9;
			case 67:return 10;
			case 69:return 11;
			case 71:return 12;
			case 72:return 13;

			default:return -1;
				break;
			}
		}
		else {
			switch (in)
			{
			case 48:return 0;
			case 50:return 1;
			case 52:return 2;
			case 53:return 3;
			case 55:return 4;
			case 57:return 5;
			case 59:return 6;
			case 60:return 7;

			case 62:return 8;
			case 64:return 9;
			case 65:return 10;
			case 67:return 11;
			case 69:return 12;
			case 71:return 13;

			default:return -1;
				break;
			}
		}
		return -1;
	}

	float time = 0;

	std::vector<note>notes;

	bool of = false;
	void load(std::string file,float s,bool offsetone)
	{
		of = offsetone;
		speed = s;
		MidiFile Midi;
		if (Midi.read(file))
		{ 
			for (int t = 0; t < Midi.getTrackCount(); t++) {
				for (int i = 0; i < Midi.getEventCount(t); i++)
				{
					MidiEvent e = Midi.getEvent(t, i);
					printf("key:%d,cmd:%d,pos:%f", e.getKeyNumber(), e.getCommandNibble(), (float)Midi.getTimeInSeconds(t, i));
					note n;
					n.key = e.getKeyNumber();
					n.command = e.getCommandNibble();
					n.pos = (float)Midi.getTimeInSeconds(t, i);
					notes.push_back(n);

					printf("\n");
				}
			}
		}

	}

	bool start;
	void play()
	{ 
		start = true;
	}

	void pause()
	{
		start = false;
	}

	void reset()
	{
		for (unsigned int i = 0; i < notes.size(); i++) {
			notes[i].isplay = false;
		}
		time = 0;
		start = false;
	}

	void stop()
	{
		time = 0;
		start = false;
	}

	float speed = 0;

	void onTick()
	{
		if (start) {
		 
			for (unsigned int i = 0; i < notes.size(); i++) {
				if (notes[i].pos <= time) {
					if (!notes[i].isplay) {
						if (notes[i].command == 144) {

							printf("%d \n", (notes[i].key));

							//printf(" a%d \n", notes[i].key);
							for (unsigned int a = 0; a < keys.size(); a++) {
								if (keys[a]->id == castkey(notes[i].key, of)) {
					
									keys[a]->click();
									//printf(" b%d \n",   notes[i].key);
								}
							}

						}
					}
					notes[i].isplay = true;
				}
			}

			time = time + speed;

		}
	}


};