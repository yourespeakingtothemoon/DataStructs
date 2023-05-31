#include "MazeGraph.h"
#include <unordered_map>
#include <queue>

MazeGraph::MazeGraph(std::vector<Node*> n, Node* s, Node* e) : nodes(n), start(s), end(e)
{
}


std::vector<Node*> MazeGraph::shortestPath()
{
	//Breadth First Search (BFS)
	//init all stuff
	std::queue <Node*> nodeQueue;
	std::vector<Node*> visited;
	std::vector<Node*> path;
	//unordered_maps saved my life, you learn something new about C every day
	std::unordered_map<Node*, Node*> prev;
	
	//BEGIN
	nodeQueue.push(start);
	visited.push_back(start);
	prev[start] = nullptr;
	
	while (!nodeQueue.empty())
	{
		//while its empty loop this:
		
		//deQueue current node
		Node* current = nodeQueue.front();
		nodeQueue.pop();
		if (current == end)
		{
			//if we found the end, break
			break;
		}
		for (int i = 0; i < current->connections.size(); i++)
		{
			//loop through all connections
			if (std::find(visited.begin(), visited.end(), current->connections[i]) == visited.end())
			{
				//if we havent visited this node yet add to the queue
				//add to visited
				//add to prev
				nodeQueue.push(current->connections[i]);
				visited.push_back(current->connections[i]);
				prev[current->connections[i]] = current;
			}
		}
	}
	Node* current = end;
	while (current != nullptr)
	{
		//rebuild path based on prev
		path.push_back(current);
		current = prev[current];
	}
	//reverse the vector
	std::reverse(path.begin(), path.end());
	//you win!!
	return path;
	
}


