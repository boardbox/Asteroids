#ifndef INPUT_H
#define INPUT_H

class Player;

class Input{
	Player &p;
	int &run;

	public:
	Input(Player &pl,int &run);
	void getInput() ;
};

#endif
