void draw_water(const set<pair<int,int>> & water) {
	system("clear");
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			int ox = x - width/2+j;
			int oy = y + height/2-i;
			if(objects.count({ox,oy}))
				if(!water.count({ox,oy}))
					cout << configs["graphics"][objects[{ox,oy}]];
				else
					cout << configs["water"][objects[{ox,oy}]];
			else cout << configs["graphics"]["empty"];
		}
		cout << '\n';
	}
}
void draw() {
	system("clear");
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			int ox = x - width/2+j;
			int oy = y + height/2-i;
			if(objects.count({ox,oy}))
				cout << configs["graphics"][objects[{ox,oy}]];
			else cout << configs["graphics"]["empty"];
		}
		cout << '\n';
	}
}
