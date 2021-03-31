#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
using namespace std;
#include "configs.h"
	map<string,map<string,char>> configs = load_configs();
	int width = 20;
	int height = 10;
	int x = 0;
	int y = 0;
	map<pair<int,int>,string> objects;
	double speed = 0.1;
#include "drawings.h"
#include "simulations.h"
int main() {
	while(1) {
		draw();
		system("stty raw");
        	char key = getchar(); 
        	system("stty cooked");
		if(key == configs["hotkeys"]["quit"]) {
			return 0;
		}
		if(key == configs["hotkeys"]["up"]) {
			y++;
		}
		if(key == configs["hotkeys"]["down"]) {
			y--;
		}
		if(key == configs["hotkeys"]["left"]) {
			x--;
		}
		if(key == configs["hotkeys"]["right"]) {
			x++;
		}
		for(auto obj_name : {"crane","tube","fontain","doorv","doorh"}) {
			if(key == configs["hotkeys"][obj_name]) {
				if(!objects.count({x,y}))
					objects[{x,y}] = obj_name;
				else
					objects.erase({x,y});
			}
		}
		if(key == configs["hotkeys"]["simulate"]) {
			simulate();
		}
		if(key == configs["hotkeys"]["erase"]) {
			objects = map<pair<int,int>,string>();
		}
		if(key == configs["hotkeys"]["increaseSpeed"] && speed > 0.1) {
			speed -= 0.1;
		}
		if(key == configs["hotkeys"]["decreaseSpeed"]) {
			speed += 0.1;
		}
	}
}
