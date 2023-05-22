#pragma once
#include <string>
#include <array>

	template<typename T>
	class Node
	{
	public:
		Node();
		Node(T value);
		~Node();
		
		void Add(T value);
		Node<T>* Remove(T value, Node<T>* rt);
		bool Contains(T value);
		void Clear(Node<T>* rt);

		Node<T>* GetLeft(Node<T>* n);
		Node<T>* GetRight(Node<T>* n);
		
		int Count();
		int Height();
		
		T* ToArray();
		void ArrayBuilder(T* array, int index);
		
		bool DirectionChecker();
		
		void Visualizer(const std::string& prefix = "", bool isLeft = false);
		
		std::string InOrder();
		std::string PreOrder();
		std::string PostOrder();
		
		T value;
		Node* left;
		Node* right;
		Node* parent;
	};

	template<typename T>
	inline Node<T>::Node()
	{
		//empty
		this->value = NULL;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		
	}

	template<typename T>
	inline Node<T>::Node(T value)
	{
		this->value = value;
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}

	template<typename T>
	inline Node<T>::~Node()
	{
		this->Clear();
		//delete this;
		
	}

	template<typename T>
	inline void Node<T>::Add(T value)
	{
		if (this->value) {
			if (value != this->value) {
				if (value < this->value)
				{
					if (this->left == nullptr)
					{
						this->left = new Node(value);
						this->left->parent = this;
					}
					else
					{
						this->left->Add(value);
					}
				}
				else
				{
					if (this->right == nullptr)
					{
						this->right = new Node(value);
						this->right->parent = this;
					}
					else
					{
						this->right->Add(value);
					}
				}
			}
			else {
				return;
			}
		}
		else
		{
			this->value = value;
		}
	}
	
	template<typename T>
	inline Node<T>* Node<T>::GetLeft(Node<T>* n)
	{
		
		if (n->left == nullptr)
		{
			return n;
				//recursive black magic again
		}
		else
		{
			return GetLeft(n->left);
		}
	
	}
	
	template<typename T>
	inline Node<T>* Node<T>::GetRight(Node<T>* n)
	{
		if (n->right == nullptr)
		{
			return n;
			//recursive black magic a third time
		}
		else
		{
			return GetLeft(n->right);
		}
	}

	template<typename T>
	inline Node<T>* Node<T>::Remove(T value, Node<T>* rt)
	{
		//we know contains works, lol
		if (this->Contains(value))
		{
			//attempt 2
			if (rt == nullptr)
			{
				return this;
			}
			else {

				if (value < rt->value)
				{
					rt->left = Remove(value, rt->left);
				}
				else if (value > rt->value)
				{
					rt->right = Remove(value, rt->right);
				}
				else
				{
					if (rt->left == nullptr)
					{
						return rt->right;

					}
					else if (rt->right == nullptr)
					{
						return rt->left;
					}


					rt->value = GetLeft(rt->right)->value;
					rt->right = Remove(rt->value, rt->right);


				}
				return rt;
			}
		}
		else { return rt; }
		}
		
		//Node* nodeToRemove = nullptr;
		//int direction = 0;

		////find node
		//if (value < this->value)
		//{
		//	if (this->left == nullptr)
		//	{
		//		return;
		//	}
		//	else if (this->left->value == value)
		//	{
		//		nodeToRemove = this->left;
		//		direction = -1;
		//	}
		//	else
		//	{
		//		this->left->Remove(value);
		//	}
		//}
		//else if (value > this->value)
		//{
		//	if (this->right == nullptr)
		//	{
		//		return;
		//	}
		//	else if (this->right->value == value)
		//	{
		//		nodeToRemove = this->right;
		//		direction = 1;
		//	}
		//	else
		//	{
		//		this->right->Remove(value);
		//	}

		//}
		//else
		//{
		//	nodeToRemove = this;
		//}
		//
		//if (nodeToRemove) {
		//	//if node is a leaf, delete it
		//	if (!nodeToRemove->left && !nodeToRemove->right) {
		//		delete nodeToRemove;
		//		return;
		//	}

		//	//if node has one child, replace it with its child
		//	if (nodeToRemove->left || nodeToRemove->right)
		//	{
		//		switch (direction)
		//		{
		//		case -1:
		//			this->left = nodeToRemove->left;
		//			break;
		//		case 1:
		//			this->right = nodeToRemove->left;
		//			break;

		//		}
		//		// if node to remove also has a right child make that child the child of the left node
		//		
		//	}
		//	if (nodeToRemove->right && nodeToRemove->left)
		//	{
		//		switch (direction)
		//		{
		//		case -1:
		//			this->left->right = nodeToRemove->right;
		//			break;
		//		case 1:
		//			this->right->right = nodeToRemove->right;
		//			break;

		//		}


		//	}
		//}

	

	template<typename T>
	inline bool Node<T>::Contains(T value)
	{
		//traverse
		if (this->value == value)
		{
			return true;
		}
		else
		{
			if (value < this->value)
			{
				if (this->left == nullptr)
				{
					return false;
				}
				else
				{
					return this->left->Contains(value);
				}
			}
			else
			{
				if (this->right == nullptr)
				{
					return false;
				}
				else
				{
					return this->right->Contains(value);
				}
			}
		}
	}

	template<typename T>
	inline void Node<T>::Clear(Node<T>* n)
	{
		if (n==nullptr) {
			return;
		}
		// recursive black magic ig lol
		if (n.left != nullptr)
		{
			Clear(n.left);
		}
		if (n.right != nullptr)
		{
			Clear(n.right);
		}
		
		delete n;
		n = nullptr;
	}
	

	template<typename T>
	inline int Node<T>::Count()
	{
		if (this)
		{
			int count= 1;
			return count + this->left->Count() + this->right->Count();
		}
		else
		{
			//if null return 0
			return 0;
		}
	}

	template<typename T>
	inline int Node<T>::Height()
	{
		if (this)
		{
			int leftHeight = 0;
			int rightHeight = 0;
			if (this->left)
			{
				leftHeight = this->left->Height();
			}
			if (this->right)
			{
				rightHeight = this->right->Height();
			}
			if (leftHeight > rightHeight)
			{
				return leftHeight + 1;
			}
			else
			{
				return rightHeight + 1;
			}
		}
		else
		{
			//if null return 0
			return 0;
		}
	}

	template<typename T>
	inline T* Node<T>::ToArray()
	{
		if (this->value) {
			//create array
			T* array = new T[this->Count()];
			this->ArrayBuilder(array, 0);
			//return array
			return array;
		}
		else {
			return nullptr;
		}
		
	}



	template<typename T>
	inline void Node<T>::ArrayBuilder(T* array, int index)
	{
		
		//if left exists, add it to the array
		if (this->left)
		{
			this->left->ArrayBuilder(array, index);
		}
		if (!this->left && !this->right)
		{
			array[index] = this->value;
			index++;
		} 
		//if right exists, add it to the array
		if (this->right)
		{
			this->right->ArrayBuilder(array, index + 1);
		}
	}

	template<typename T>
	inline bool Node<T>::DirectionChecker()
	{
		if (this->parent ==nullptr)
		{
			return true;
		}
		else {
			if (this->value > this->parent->value)
			{
				
			return this->parent->DirectionChecker();
			}
			else
			{
				return false;
			}
		}
		
	}

	template<typename T>
	inline void Node<T>::Visualizer(const std::string& prefix, bool isLeft)
	{
		//built using GPT4
		/*if (right) {
			right->Visualizer(prefix + (isLeft ? "│   " : "    "), false);
		}

		std::cout << prefix;
		std::cout << (isLeft ? "└── " : "┌── ");
		std::cout << value << std::endl;

		if (left) {
			left->Visualizer(prefix + (isLeft ? "    " : "│   "), true);
		}*/
		//adjusted because codepage issues
	/*	if (right) {
			right->Visualizer(prefix + (isLeft ? "|   " : "    "), false);
		}

		std::cout << prefix;
		std::cout << (isLeft ? "\\-- " : "/-- ");
		std::cout << value << std::endl;

		if (left) {
			left->Visualizer(prefix + (isLeft ? "    " : "|   "), true);
		}*/
	/*	if (right) {
			right->Visualizer(prefix + (isLeft ? "     " : " |   "), false);
		}

		std::cout << prefix;

		if (isLeft) {
			std::cout << " \\-- ";
		}
		else {
			std::cout << " /-- ";
		}

		std::cout << value << std::endl;

		if (left) {
			left->Visualizer(prefix + (isLeft ? " |   " : "     "), true);
		}*/
		if (right) {
			right->Visualizer(prefix + (isLeft ? "     " : " |   "), false);
		}

		std::cout << prefix;

		if (isLeft) {
			std::cout << " /-- ";
		}
		else {
			std::cout << " \\-- ";
		}

		std::cout << value << std::endl;

		if (left) {
			left->Visualizer(prefix + (isLeft ? " |   " : "     "), true);
		}
		//Im just gonna deal with it looking awkward
	
	}

	template<typename T>
	inline std::string Node<T>::InOrder()
	{
		std::string out = "";
		//int count = 0;
		//count++;
		if (this) {
			//count -> this->Count();
			if (this->left)
			{
				out += this->left->InOrder();
			}
			
				if (this->DirectionChecker()) {
			if (!this->right && !this->left)
			{
				//its a leaf
					out += std::to_string(this->value);
				}
			if (!this->right)
			{
				out += std::to_string(this->value);
			}
			else
			{
					out += std::to_string(this->value)+", ";
				}
				
			}
			else
			{
				//not a leaf
					out += std::to_string(this->value)+", ";
				
			}
			
			

			if (this->right)
			{

				out += this->right->InOrder();

			}
		}
		return out;
	}

	template<typename T>
	inline std::string Node<T>::PreOrder()
	{
		std::string out = "";
		if (this) {

			out += std::to_string(this->value);


			//	out += std::to_string(this->value) + ", ";
			if (this->left) {
				out += ", " + this->left->PreOrder();
			}
			if (this->right) {
				out += ", " + this->right->PreOrder();
			}
			return out;
		}
	}

	template<typename T>
	inline std::string Node<T>::PostOrder()
	{
		std::string out = "";
		if (this) {
			if (this->left)
			{
				out += this->left->PostOrder();
			}
			if (this->right)
			{
				out += this->right->PostOrder();
			}
			if (this->parent == nullptr)
			{
				out += std::to_string(this->value);
			}
			else {
				out += std::to_string(this->value) + ", ";
			}
		}
		return out;
	}
	