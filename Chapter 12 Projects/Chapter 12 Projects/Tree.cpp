#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
	Node* pNodeGandhi = new Node("Are you thinking of Gandhi?", NULL, NULL);
	Node* pNodeSanta = new Node("Are you thinking of Santa?", NULL, NULL);
	People.push_back(pNodeGandhi->m_Question);
	People.push_back(pNodeSanta->m_Question);
	Node* pNodeQuestion = new Node("Is/was the person real?", pNodeGandhi, pNodeSanta);
	m_pRoot = pNodeQuestion;
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
}


Tree::~Tree()
{
	Delete(m_pRoot);
	//Clear the vector
	People.clear();
}

void Tree::Save(Node* pNode)
{
		fstream New("list.txt", ios::app);
		WriteNode(pNode, New);
		New.close();

}

void Tree::Load(Node *tree)
{
	ifstream Load("list.txt");
	LoadNodes(tree, Load);
	Load.close();
}

void Tree::Reset()
{
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
}

//Load Function..
void Tree::LoadNodes(Node* pNode, ifstream &file) {
	if (!file)return;
	string str;
	getline(file, str);
	if (str == "")return;
	Node* temp = m_pCurrent;
	m_pCurrent = pNode;
	m_pCurrentParent = temp;
	if (m_pCurrent == NULL) m_pCurrent = new Node(str, NULL, NULL);
	m_pCurrent->m_Question = str;
	LoadNodes(m_pCurrent->m_pNo, file);
	LoadNodes(m_pCurrent->m_pYes, file);
}

void Tree::WriteNode(Node * pNode, fstream & file)
{
	if (!pNode)return;
	file << pNode->m_Question << endl;
	WriteNode(pNode->m_pNo, file);
	WriteNode(pNode->m_pYes, file);
}

void Tree::Delete(Node * pNode)
{
	if (pNode != NULL) {
		Delete(pNode->m_pYes);
		Delete(pNode->m_pNo);
		delete pNode;
		pNode = NULL;
	}
}

void Tree::DisplayAll(Node* pNode) {
	if (pNode != NULL) {
		DisplayAll(pNode->m_pYes);
		DisplayAll(pNode->m_pNo);
		cout << pNode->m_Question << endl;
	}
}

bool Tree::DisplayCurrentQuestion()
{
	if (m_pCurrent == NULL) {
		return false;
	}
	cout << m_pCurrent->m_Question;
	return (!m_pCurrent->IsFinalQuestion());
}

void Tree::DisplayAllQuestions()
{
	
	for (iter = People.begin(); iter < People.end(); iter++)
	{
		cout << *iter << endl;
	}
}

void Tree::DisplayAllNumbered()
{
	int num = 1;
	for (iter = People.begin(); iter < People.end(); iter++)
	{
		cout << num << ": " << *iter << endl;
		num++;
	}
}

void Tree::NextQuestion(char answer)
{
	if (m_pCurrent == NULL) {
		return;
	}
	if (m_pCurrent->IsFinalQuestion()) {
		return;
	}
	m_pCurrentParent = m_pCurrent;
	
	if (answer == YES) {
		m_pCurrent = m_pCurrent->m_pYes;
	}
	else {
		m_pCurrent = m_pCurrent->m_pNo;
	}
	system("CLS");
}

void Tree::AddPerson()
{
	cout << "Who are you thinking of?: ";
	string name;
	cin.ignore();
	getline(cin, name);
	cout << endl;
	cout << "What question would distinguish these two people?" << endl;
	string question;
	getline(cin, question);
	Node* pNodePerson = new Node("Are you thinking of " + name + "?", NULL, NULL);

	People.push_back(pNodePerson->m_Question);

	Node* pNodeQuestion = new Node(question, NULL, NULL);
	char answer = AskYesNo("What would the answer be for " + name + "?");
	if (answer == YES) {
		pNodeQuestion->m_pYes = pNodePerson;
		pNodeQuestion->m_pNo = m_pCurrent;
	}
	else {
		pNodeQuestion->m_pYes = m_pCurrent;
		pNodeQuestion->m_pNo = pNodePerson;
	}
	if (m_pCurrentParent->m_pYes == m_pCurrent) {
		m_pCurrentParent->m_pYes = pNodeQuestion;
	}
	else {
		m_pCurrentParent->m_pNo = pNodeQuestion;
	}
}

Node * Tree::GetNode()
{
	return m_pRoot;
}

void Tree::SetNode()
{
		m_pCurrent = m_pRoot;
}

char Tree::AskYesNo(const string & question)
{
	char response;
	do
	{
		cout << question;
		cout << "(" << YES << "/" << NO << "): ";
		cin >> response;
	} while (response != YES && response != NO);
	return response;
}
