#pragma once
#include "stdafx.h"
#include "Stack.h"

Stack::Stack() :
	m_pHead(NULL) {}

Stack::~Stack()
{
	Clear();
}

bool Stack::IsEmpty() const
{
	if (m_pHead != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void Stack::Display() const
{
	if (m_pHead == NULL) {
		cout << "Items in stack: " << endl;
		cout << "<Empty>" << endl;
		return;
	}
	Node2* pNode = m_pHead;
	cout << "Items in stack: " << endl;
	while (pNode != NULL) {
		cout << pNode->m_intData << endl;
		pNode = pNode->m_pNext;
	}
}

void Stack::Count() const
{
	Node2* pNode = m_pHead;
	int total = 0;
	while (pNode != NULL) {
		++total;
		pNode = pNode->m_pNext;
	}
	cout << "Total items: " << total << endl;
}

int Stack::CountMod() const {
	Node2* pNode = m_pHead;
	int total = 0;
	while (pNode != NULL) {
		++total;
		pNode = pNode->m_pNext;
	}
	return total;
}

int Stack::WinCount() {
	Node2* pNode = m_pHead;
	int total = 0;
	while (pNode != NULL) {
		++total;
		pNode = pNode->m_pNext;
	}
	return total;
}

int Stack::Top() const
{
	if (m_pHead != NULL)
	{
		cout << "\nNumber on top of stack: " << m_pHead->m_intData << endl;
		return 0;
	}
	else {
		cout << "\nError: Cannot display top of empty stack" << endl;
		return -1;
	}
}

int Stack::GetTop() {
	if (m_pHead == NULL) {
		return 5;
	}
	else {
		return m_pHead->m_intData;
	}
}

string Stack::GetTopMod() {
	if (m_pHead == NULL) {
		return "";
	}
	else {
		return m_pHead->m_Data;
	}
}

void Stack::Push(int data)
{
	Node2* pNode = new Node2(data);
	pNode->m_pNext = m_pHead;
	m_pHead = pNode;
	cout << "\nAdding new number: " << data << endl;
}

void Stack::PushMod(string data) {
	Node2* pNode = new Node2(data);
	pNode->m_pNext = m_pHead;
	m_pHead = pNode;
}

void Stack::DisplayMod() const
{
	if (m_pHead == NULL) {
		for (int i = 0; i < 5; i++)
		{
			cout << "\t|" << endl;
		}
		return;
	}
	Node2* pNode = m_pHead;
	while (pNode != NULL) {
		cout << pNode->m_Data << endl;
		pNode = pNode->m_pNext;
	}
	if (CountMod() < 5) {
		for (int i = CountMod(); i < 5; i++)
		{
			cout << "\t|" << endl;
		}
	}

}

int Stack::Pop()
{
	Node2* pNode = m_pHead;
	if (pNode == NULL) {
		cout << "\nError: Cannot 'pop' from empty stack" << endl;
	}
	if (pNode != NULL) {
		cout << "\nItem being popped from stack: " << pNode->m_intData << endl;
		int temp = pNode->m_intData;
		pNode = m_pHead->m_pNext;

		m_pHead = NULL;
		m_pHead = pNode;
		return temp;
	}
}

string Stack::PopMod()
{
	Node2* pNode = m_pHead;
	if (pNode == NULL) {
		cout << "\nError: Cannot 'pop' from empty stack" << endl;
	}
	if (pNode != NULL) {
		cout << "\nItem being popped from stack: " << pNode->m_Data << endl;
		string temp = pNode->m_Data;
		pNode = m_pHead->m_pNext;
		m_pHead = NULL;
		m_pHead = pNode;
		return temp;
	}
}

void Stack::Clear()
{
	while (m_pHead != NULL) {
		Node2* pTemp = m_pHead->m_pNext;
		m_pHead = NULL;
		m_pHead = pTemp;
		//delete pTemp;
	}
	m_pHead = NULL;
	cout << "\nStack Cleared!" << endl;
}


