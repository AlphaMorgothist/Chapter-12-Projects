#pragma once
#include "Node.h"
#include <vector>
#include <fstream>

class Tree {
public:
	Tree();
	~Tree();
	void Save(Node* pNode);
	void Load(Node* tree);
	void Reset();
	void WriteNode(Node* pNode, fstream &file);
	void LoadNodes(Node* pNode, ifstream &file);
	void Delete(Node* pNode);
	bool DisplayCurrentQuestion();
	void DisplayAllQuestions();
	void DisplayAllNumbered();
	void DisplayAll(Node* pNode);
	void NextQuestion(char answer);
	void AddPerson();
	Node* GetNode();
	void SetNode();
	char AskYesNo(const string &question = "");
	static const char YES = 'y';
	static const char NO = 'n';

private:
	Node* m_pRoot;
	Node* m_pCurrent;
	Node* m_pCurrentParent;
	vector<string> People;
	vector<string>::iterator iter;
};