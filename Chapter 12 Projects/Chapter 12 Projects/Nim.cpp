#include "stdafx.h"
#include "Nim.h"
#include <ctime>

NimPlayer::NimPlayer(string & name) :
	m_Name(name)
{
}

string NimPlayer::GetName()
{
	return m_Name;
}

int NimPlayer::StickPrompt()
{
	return 0;
}

Human::Human(string &name) :
	NimPlayer(name)
{
}

int Human::StickPrompt()
{
	int temp;
	while (true) {
		cout << "Player: " << m_Name << endl;
		cout << "\nPick a number of sticks to remove from the pile (1-4)" << endl;
		cout << "Choice: ";
		cin >> temp;
		if (temp > 4 || temp < 0) {
			cout << "Invalid choice" << endl;
		}
		else {
			return temp;
		}
	}
	return 0;
}

int Pile::GetSticks()
{
	return m_Sticks;
}

void Pile::SetSticks()
{
	srand(time(NULL));
	cout << "\nNumber of sticks to play with: ";
	int temp;
	cin >> temp;
	if (temp > 4) {
		m_Sticks = temp * (rand() % 2 + 1);
	}
	else {
		m_Sticks = rand() % 50 + 13;
	}
}

void Pile::RemSticks(NimPlayer *player, int rem)
{
	cout << "Player " << player->GetName() << " removes " << rem << " sticks from the pile" << endl;
	m_Sticks -= rem;
}

Computer::Computer(string & name) :
	NimPlayer(name)
{
}

int Computer::StickPrompt(int sticks)
{
	if (sticks <= 4) { return 4; }
	int checkN = sticks - 4;
	if (checkN > 4) {
		StickPrompt(checkN);
	}
	else if (checkN == 4) {
		return 1;
	}
	else if (checkN == 3) {
		return 2;
	}
	else if (checkN == 2) {
		return 3;
	}
	else if (checkN == 1) {
		return 4;
	}
	else if (checkN == 0) {
		return 1;
	}

}
