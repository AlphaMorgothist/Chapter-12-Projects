#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	m_Tree = new Tree();
}

void Game::DisplayInstructions()
{
	cout << "\tWelcome to Famous or Infamous" << endl;
	cout << "\nThink of a famous or infamous person ";
	cout << "and I'll try and guess his or her (or ze'zez, or xe'ses) name.";
	cout << endl;

}

void Game::DisplayAll(Tree* tree)
{
	m_Tree->DisplayAll(tree->GetNode());
	//m_Tree.DisplayAllQuestions();
}

void Game::DisplayAllNumbered() {
	m_Tree->DisplayAllNumbered();
}

void Game::Play()
{
	m_Tree->Reset();
	//Loading functions
	//m_Tree->Load(m_Tree->GetNode());
	//m_Tree->SetNode();
	char response;
	while (m_Tree->DisplayCurrentQuestion()) {
		response = m_Tree->AskYesNo();
		m_Tree->NextQuestion(response);
	}
	response = m_Tree->AskYesNo();
	if (response == m_Tree->YES) {
		cout << "I guessed it!" << endl;
	}
	else {
		cout << "I give up." << endl;
		m_Tree->AddPerson();
	}
}

Tree * Game::GetTree()
{

	return m_Tree;
}
