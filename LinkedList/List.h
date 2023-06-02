#pragma once
#include <vector>
struct Node
{
	Node(char name, std::vector<Node*> neighbors) : letter(name), connections(neighbors) {}
	Node(char name) : letter(name) {}
	
	
	char letter;
	//Node*[] connections;
	std::vector<Node*> connections;
};