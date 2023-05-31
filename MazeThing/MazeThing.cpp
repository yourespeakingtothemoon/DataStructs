// MazeThing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "MazeGraph.h"
#include <string>

class fileMgmt {
	//this is less file management and just domething to hold methods. I dont feel like going all MVC on this
	
public:
	MazeGraph* FileIn(std::string filename)
	{
		//read in file

		std::fstream file;
		file.open(filename);
		std::vector<char> letters;

		if (file.is_open())
		{
			std::string line;
			std::getline(file, line);

			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] != ' ' && line[i] != ',')
				{
					letters.push_back(line[i]);
				}
			}

			
			
			std::vector<Node*> nodes;
			//using letters make a group of nodes
			for (int i = 0; i < letters.size(); i++)
			{
				nodes.push_back(new Node(letters[i]));
			}

			//find start and end
			Node* start = nullptr;
			Node* end = nullptr;
			std::getline(file, line);
			start = FindNode(nodes, line[0]);
			end = FindNode(nodes, line[2]);
			
			while (std::getline(file, line))
			{

				for (int i = 1; i < line.length(); i++)
				{
					if (line[i] != ' ' && line[i] != ',')
					{
						//line[0] is the node
						//line[i] is the connection
						//find the node with the letter line[0]
						FindNode(nodes, line[0])->connections.push_back(FindNode(nodes, line[i]));
						//find the node with the letter line[i]
						//add connection
						//no need to to that in the reverse, this isnt two way connection. 

					}


				}
			}


			return new MazeGraph(nodes,start, end);
		}
		else
		{
			std::cout << "File not found" << std::endl;
			return 0;
		}

		// Format
		// File Input:



		// 1st line: list of node letters, first is start last is end
			/*A, B, C, D, E, F
			* //lines following, all connections, first letter is a letter, following is its connecting nodes
			A, E
			A, B
			B, A, C, D, F
			C, B
			D, B, E, F
			E, D, F
			F, B, D, E*/
			//create nodes

			//create connections
			//create start and end nodes
	}

	Node* FindNode(std::vector<Node*> nodes, char letter)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i]->letter == letter)
			{
				return nodes[i];
			}
		}
		return nullptr;
	}
	
	void PrintSolution(MazeGraph* maze) {
		if (maze) {
			std::vector<Node*> path = maze->shortestPath();
			if (path.size() < 2)
			{
				std::cout << "No solution found" << std::endl;
			}
			else
			{
				std::cout << "Shortest Path: ";
				for (int i = 0; i < path.size(); i++)
				{
					if (i < path.size() - 1) {
						std::cout << path[i]->letter << " -> ";
					}
					else
					{
						std::cout << path[i]->letter;
					}

				}
				std::cout << std::endl;
			}
		}
	}

	
};
int main()
{
	//I know this is dumb but im tired and dont want to deal with c++ rn
	//const std::vector<const std::string> strings = { "make it so", "makeitso", "MAKEITSO", "Make it so!", "make it so!", "mis!", "MAKE IT SO!", "exit"};
	//that didnt work
	//this langauge is both the best and worst thing ever made
	const std::string mis = "make it so!";
	const std::string e = "exit";
	

	bool exit = false;
	fileMgmt f = fileMgmt();
    std::cout << "Hello!\n";
		std::string filename;
	while (!exit) {
		filename = "";
		std::cout << "Enter Filename (or say 'make it so!' to test all test mazes, this is case sensitive): ";
		std::getline(std::cin, filename);
		//const char* fn = filename;
		//MazeGraph* maze = nullptr; no need now
		//no switch today :(

		if (filename == e) {
			exit = true;
		}
		else if (filename == mis) {

			for (int i = 0; i < 4; i++)
			{
				f.PrintSolution(f.FileIn("mazeTest" + std::to_string(i) + ".txt"));
			}
		}
		else{
		
		
			f.PrintSolution(f.FileIn(filename));

		}
		
	}
	}
	
	
	
	




//add nodes to mazegraph
//add connections to nodes
//add start and end nodes

