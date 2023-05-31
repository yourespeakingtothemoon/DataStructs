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



class MazeGraph
{
public:
	MazeGraph(std::vector<Node*> n, Node* s, Node* e);
	//~MazeGraph();

	std::vector<Node*> shortestPath();



public:
	Node* start;
	Node* end;
	std::vector<Node*> nodes;
	
};