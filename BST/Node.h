#pragma once
namespace dsw {

	class Node
	{
	public:
		Node(int value);
		~Node();

		int value;
		Node* left;
		Node* right;
	};
	};
}
