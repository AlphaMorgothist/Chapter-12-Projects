#pragma once
#include "Tree.h"

class Game {
public:
	Game();
	void DisplayInstructions();
	void DisplayAll(Tree* tree);
	void DisplayAllNumbered();
	void Play();
	Tree* GetTree();
private:
	Tree* m_Tree;
};