// Chapter12Projects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Master.h"
#include <Windows.h>


int main()
{
	SetConsoleTitle(_T("Chapter 12 Projects"));
	int num;
	while (true) {
		cout << "\n\t\tChapter 12 Projects" << endl;
		cout << "\n1: [Projects 12.1, 12.2, 12.3] Famous and Infamous" << endl;
		cout << "2: [Projects 12.4] modified Nim" << endl;
		cout << "3: [Projects 12.5] modified Hanoi" << endl;
		cout << "0: Quit" << endl;
		cout << "\nChoice: ";
		cin >> num;
		switch (num) {
		case 0: {return 0; }break;
		case 1: {PlayForI(); }break;
		case 2: {runProj5(); }break;
		case 3: {Stack stack1; Stack stack2; Stack stack3; playHanoiMod(stack1, stack2, stack3); }
		}
	}
}

