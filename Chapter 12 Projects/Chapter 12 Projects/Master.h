#pragma once
#include "Stack.h"

void PlayForI() {
	Game ForI;
	char again;
	ForI.DisplayInstructions();
	do {
		ForI.Play();
		cout << endl << "Play again (y/n): ";
		cin >> again;
	} while (again == 'y');
	cout << endl;
	cout << "Part one of chapter 7 projects: " << endl;
	ForI.DisplayAll(ForI.GetTree());
	cout << "Part two of chapter 7 projects: " << endl;
	cout << endl;
	ForI.DisplayAllNumbered();
	//Saving Function
	ForI.GetTree()->Save(ForI.GetTree()->GetNode());
	system("pause");
 }

void TwoPlayer() {
	cin.ignore();
	cout << "\nEnter two player names" << endl;
	cout << "\nPlayer One: ";
	string temp1;
	getline(cin, temp1);
	Human *h1 = new Human(temp1);
	//cin.ignore();
	cout << "\nPlayer Two: ";
	getline(cin, temp1);
	Human *h2 = new Human(temp1);
	//cin.ignore();
	Pile *stick = new Pile();
	stick->SetSticks();
	cin.ignore();
	while (true) {
		system("CLS");
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(h1, h1->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << h1->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		system("CLS");
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(h2, h2->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << h2->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
	}
	delete stick;
	stick = NULL;
	delete h1;
	h1 = NULL;
	delete h2;
	h2 = NULL;
}

void VsAI() {
	cin.ignore();
	cout << "\nPlease enter your name: ";
	string temp;
	string comp = "Computer";
	getline(cin, temp);
	Human *H = new Human(temp);
	Computer *AI = new Computer(comp);
	Pile *stick = new Pile();
	stick->SetSticks();
	cin.ignore();
	while (true) {
		system("CLS");

		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(AI, AI->StickPrompt(stick->GetSticks()));
		if (stick->GetSticks() <= 0) {
			cout << AI->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		cout << endl;
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(H, H->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << H->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		system("pause");
	}

}

void runProj5() {
	cout << "\nPlease choose a game mode" << endl;
	cout << "1:Two players" << endl;
	cout << "2:Vs AI" << endl;
	cout << "\nChoice: ";
	int pick;
	cin >> pick;
	switch (pick) {
	case 1: {TwoPlayer(); }break;
	case 2: {VsAI(); }break;
	}
}

void initMod(Stack &stack) {
	string star1 = "\t*";
	string star2 = "\t**";
	string star3 = "\t***";
	string star4 = "\t****";
	string star5 = "\t*****";
	stack.PushMod(star5);
	stack.PushMod(star4);
	stack.PushMod(star3);
	stack.PushMod(star2);
	stack.PushMod(star1);

}

void playHanoiMod(Stack &stack1, Stack &stack2, Stack &stack3) {
	initMod(stack1);
	bool  quit = false;
	bool won = false;
	string transfer = "";
	system("CLS");
	cout << "\nYou must move the 'discs' around so that all of them end up in the correct order on the last stack.\nIf you put a larger disc on top of a smaller one, you lose." << endl;
	do
	{
		cout << "Pick a stack to move a disc from " << endl;
		cout << "\nStack 1:" << endl;
		stack1.DisplayMod();
		cout << endl;
		cout << "Stack 2:" << endl;
		stack2.DisplayMod();
		cout << endl;
		cout << "Stack 3:" << endl;
		stack3.DisplayMod();
		cout << endl;
		cout << "Stack number: ";
		int choice;
		cin >> choice;
		while (choice > 3 || choice < 1) {
			cout << "\nIllegal input. Please select a stack" << endl;
			cout << "\nStack number: ";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			if (stack1.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack1.PopMod();
			}
		}break;
		case 2: {
			if (stack2.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack2.PopMod();
			}
		}break;
		case 3: {
			if (stack3.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack3.PopMod();
			}
		}break;
		}
		while (transfer != "" && won == false) {
			cout << "\nWhich stack do you want to move the disc to? " << endl;
			cin >> choice;
			while (choice > 3 || choice < 1) {
				cout << "\nIllegal input. Please select a stack" << endl;
				cout << "\nStack number: ";
				cin >> choice;
			}
			switch (choice)
			{
			default:
				break;
			case 1: {
				if (stack1.GetTopMod() == "") {
					stack1.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack1.GetTopMod().size())
				{
					stack1.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 2: {
				if (stack2.GetTopMod() == "") {
					stack2.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack2.GetTopMod().size())
				{
					stack2.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 3: {
				if (stack3.GetTopMod() == "") {
					stack3.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack3.GetTopMod().size())
				{
					stack3.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			}
		}
		system("CLS");
		if (stack3.WinCount() == 5) {
			system("CLS");
			cout << "\nYou won!!!" << endl;
			system("pause");
			won = true;
		}
	} while (won == false);
	system("CLS");
}
