void simulate() {
	set<pair<int,int>> potoki;
	set<pair<int,int>> water;
	for(auto o : objects)
		if(o.second=="crane") {
			potoki.insert(o.first);
			water.insert(o.first);
		}
	set<pair<int,int>> nasledniki;
	while(1) {
		draw_water(water);
		cout << potoki.size() << endl;
		system((string("sleep ")+to_string(speed)).c_str());
		nasledniki = set<pair<int,int>>();
		for(auto potok : potoki) {
			int x = potok.first;
			int y = potok.second;
			vector<pair<int,int>> sides = {
				{1,0},
				{-1,0},
				{0,1},
				{0,-1}
			};
			bool continuePotok = false;
			if(objects[{x,y}]=="doorh") {
				vector<pair<int,int>> inputs;
				for(auto side : sides) {
					int nx = x + side.first;
					int ny = y + side.second;
					if(water.count({nx,ny}) && potoki.count({nx,ny})) {
						inputs.push_back({nx,ny});
					}
				}
				if(inputs.size()==1) {
					int nx = inputs[0].first;
					int ny = inputs[0].second;
					int dx = x - nx;
					int dy = y - ny;
					int opx = x + dx;
					int opy = y + dy;
					if(objects.count({opx,opy})&&
					!water.count({opx,opy})&&
					!nasledniki.count({opx,opy})) {
						nasledniki.insert({opx,opy});
						continuePotok = true;
						water.insert({opx,opy});
					}
				}
				if(inputs.size()==2) {
					auto i = inputs[0];
					auto j = inputs[1];
					int ix = i.first;
					int iy = i.second;
					int jx = j.first;
					int jy = j.second;
					if(ix != jx && iy != jy) {
						if(objects[{x,y}]=="doorh") {
							if(ix < x || jx < x) {
								nasledniki.insert({x+1,y});
								continuePotok = true;
								water.insert({x+1,y});
							} else {
								nasledniki.insert({x-1,y});
								continuePotok = true;
								water.insert({x-1,y});
							}
						}
					}
				}
			}
			if(objects[{x,y}]=="tube"||objects[{x,y}]=="crane") {
				for(auto side : sides) {
					int nx = x + side.first;
					int ny = y + side.second;
					if(objects.count({nx,ny})) {
						if((!water.count({nx,ny})||0&&
						objects[{nx,ny}]=="doorh")&&
						!nasledniki.count({nx,ny})) {
							if(objects[{nx,ny}]=="doorh") {
								nasledniki.insert({x,y});
							}
							nasledniki.insert({nx,ny});
							continuePotok = true;
							water.insert({nx,ny});
						}
					}
				}
			}
			if(!continuePotok) nasledniki.insert({x,y});

		}
		if(potoki == nasledniki) break;
		potoki = nasledniki;
	}
}
