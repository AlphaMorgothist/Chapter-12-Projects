#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node {
	friend class Tree;
public:
	Node(const string &question, Node *pYEs, Node *pNo);
	Node(Node *node);
	bool IsFinalQuestion() const;

private:
	string m_Question;
	Node* m_pYes;
	Node* m_pNo;
};

class Node2 {
	friend class List;
	friend class Stack;
public:
	Node2(const string &data);
	Node2(const int &data);
private:
	string m_Data;
	int m_intData;
	Node2* m_pNext;
};