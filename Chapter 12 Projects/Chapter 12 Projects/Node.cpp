#include "stdafx.h"
#include "Node.h"

Node::Node(const string & question, Node * pYes, Node * pNo) :
	m_Question(question), m_pYes(pYes), m_pNo(pNo)
{
	
}
Node::Node(Node* node):
	m_Question(node->m_Question), m_pYes(node->m_pYes), m_pNo(node->m_pNo)
	{}

bool Node::IsFinalQuestion() const
{
	return (m_pYes == NULL && m_pNo == NULL);
}

Node2::Node2(const string &data) :
	m_Data(data), m_pNext(NULL)
{}

Node2::Node2(const int &data) :
	m_intData(data), m_pNext(NULL)
{}

