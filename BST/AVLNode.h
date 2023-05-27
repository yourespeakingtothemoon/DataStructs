#pragma once
#include <iostream>
#include "node.h"

template <typename T>
class AVLNode : public Node<T>
{
	//base behavior is the same besides add and remove.
public:
	AVLNode<T>(T value):Node<T>(value)
	{
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;

	//	
	//	//change balance factor
	//	//this->balanceFactor = this->right->Height() - this->left->Height();
	///*	if (this->parent)
	//	{
	//		UpdateBalanceF(this->parent);
	//	}*/
	//	//hope this works
	//	//update: it didnt work
		}

	
	void Add(T value) 
	{
		if (this->value) {
			if (value != this->value) {
				if (value < this->value)
				{
					if (this->left == nullptr)
					{
						this->left = new AVLNode(value);
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
						this->right = new AVLNode(value);
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
		Balance();
	}

	void Remove(T value)
	{
		Node<T>::Remove(value);
		//???
	//	UpdateBalanceF(this);
		Balance();
	}

	//void UpdateBalanceF(Node<T>* n){
	//	n->balanceFactor = n->right->Height() - n->left->Height();
	//	if (n->parent) {
	//		UpdateBalanceF(n->parent);
	//	}
	//}
	
	void Balance()
	{
		//key 
		//>1 is right heavy
		//<-1 is left heavy
		//0,1,-1 is balanced
		if (this->right->Height() - this->left->Height() > 1)
		{
			if (this->right->balanceFactor > 0)
			{
				this->leftRot();
			}
			else
			{
				this->right->rightRot();
				this->leftRot();
			}
		}
		else if (balanceFactor < -1)
		{
			
			if (this->left->right->Height() - this->left->left->Height() > 0)
			{
				this->left->leftRot();
				this->rightRot();
			}
			else
			{
				this->rightRot();
			}
		}

	}
	


	//rotations
	void leftRot()
	{
		AVLNode<T>* ret = this->right;
		this->right = ret->left;
		ret->left = this;
		*this = *ret;
	}
	void rightRot()
	{
		AVLNode<T>* ret = this->left;
		this->left = ret->right;
		ret->right = this;
		*this = *ret;
	}





	public:
		int balanceFactor;
		AVLNode<T>* left = nullptr;
		AVLNode<T>* right = nullptr;
		AVLNode<T>* parent = nullptr;


};