#pragma once
#include <iostream>
#include <string>
//#include <vector>
#include "Node.h"
namespace dsw
{
	class Tree
	{
	public:
		Tree();
		~Tree();

		void insert(int value);
		void remove(int value);
		bool contains(int value);
		void print();
		void insert(int value, Node* node);
		void remove(int value, Node* node);
		bool contains(int value, Node* node);
		void print(Node* node);
		
	private:
		Node* root;
		//std::vector<Node*>
			
	};
	}
}