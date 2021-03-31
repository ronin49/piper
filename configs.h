map<string,char> load_config(const string & filename) {
	ifstream file(string(".config/")+filename+".piper");
	map<string,char> config;
	while(!file.eof()) {
		char value;
		file >> value;
		string parameter;
		file >> parameter;
		config[parameter] = value;
	}
	file.close();
	if(filename=="graphics" && !config.count("empty"))
		config["empty"] = ' ';
	return config;
}
map<string,map<string,char>> load_configs() {
	map<string,map<string,char>> configs;
	for(auto filename : {"hotkeys","graphics","water"}) {
		configs[filename] = load_config(filename);
	}
	return configs;
}
