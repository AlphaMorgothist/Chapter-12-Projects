#pragma once
#include "Game.h"

class NimPlayer {
public:
	//friend Pile;

	NimPlayer(string &name);
	string GetName();
	virtual int StickPrompt();
protected:
	string m_Name;
};

class Human : public NimPlayer {
public:
	Human(string &name);
	int StickPrompt();
};

class Pile {
public:
	//friend NimPlayer;
	int GetSticks();
	void SetSticks();
	void RemSticks(NimPlayer *player, int rem);
private:
	int m_Sticks;
};

class Computer : public NimPlayer {
public:
	Computer(string &name);
	int StickPrompt(int sticks);
};