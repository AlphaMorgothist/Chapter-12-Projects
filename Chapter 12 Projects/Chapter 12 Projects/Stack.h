#pragma once
#include "Nim.h"

class Stack {
public:
	Stack();
	~Stack();
	bool IsEmpty() const;
	void Display() const;
	void Count() const;
	int CountMod() const;
	int Top() const;
	void Push(int data);
	int Pop();
	string PopMod();
	void Clear();
	int GetTop();
	string GetTopMod();
	int WinCount();
	void PushMod(string data);
	void DisplayMod() const;

private:
	static const int ERRORED = -1;
	Node2* m_pHead;
};