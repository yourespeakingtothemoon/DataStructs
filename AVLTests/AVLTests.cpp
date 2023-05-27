#include "pch.h"
#include "CppUnitTest.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTests
{
	TEST_CLASS(AVLTests)
	{
	public:
		


		//making sure it all works
		TEST_METHOD(RightRotateTestBasic)
		{
			Node<int>* n = new Node<int>(40);
			n = n->Add(30);
			n = n->Add(20);

			Node<int>* n2 = new Node<int>(30);
			n2 = n2->Add(20);
			n2 = n2->Add(40);
			
			std::string s = n->PostOrder();
			std::string t = n2->PostOrder();
			Assert().AreEqual(t, s);
			
		}

		TEST_METHOD(LeftRotateTestBasic)
		{
			Node<int>* n = new Node<int>(40);
			n = n->Add(50);
			n = n->Add(60);

			Node<int>* n2 = new Node<int>(50);
			n2 = n2->Add(40);
			n2 = n2->Add(60);

			std::string s = n->PostOrder();
			std::string t = n2->PostOrder();
			Assert().AreEqual(t, s);
			delete n;
			delete n2;
		}

		TEST_METHOD(RandomAddTest)
		{
			
				Node<int>* n = new Node<int>(rand()%100);
				for (int a = 0; a < 16; a++)
				{
					n = n->Add(rand()%100);
				}
				Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
				delete n;
			
		}
		
		TEST_METHOD(DiamondRemovalTest)
		{
			//double rotation test, I figured if one works the other should so I am not doing this exact case twice
			Node<int>* n = new Node<int>(40);
			n = n->Add(60);
			n = n->Add(30);
			n = n->Add(50);
			n = n->Remove(40,n);
			
			std::string s = n->PostOrder();
			std::string t = "30, 60, 50";
			Assert().AreEqual(t, s);
			delete n;
		}

		TEST_METHOD(DiamondZigZagInsertTest)
		{
			//unbalanced subtree test
			Node<int>* n = new Node<int>(40);
			n = n->Add(60);
			n = n->Add(30);
			n = n->Add(50);
			n = n->Add(55);
			
			std::string s = n->PostOrder();
			std::string t = "30, 55, 60, 50, 40";
			delete n;
		}

		TEST_METHOD(SubtreeRootRemove)
		{
			//unbalanced subtree test
			Node<int>* n = new Node<int>(40);
			n = n->Add(30);
			n = n->Add(50);
			n = n->Add(35);
			n = n->Add(55);
			n = n->Add(20);
			n = n->Add(33);
			n = n->Remove(30, n);

			std::string s = n->PostOrder();
			std::string t = "20, 35, 33, 55, 50, 40";
			Assert().AreEqual(t, s);
			delete n;
		}
		
		TEST_METHOD(CascadeTest)
		{
			Node<int>* n = new Node<int>(99);
			n = n->Add(150);
			n = n->Add(50);
			n = n->Add(75);
			n = n->Add(65);
			n = n->Add(60);
			
			//this test resulted in HOURS of DEBUGGING
			//My rotations did not work in this edge case
			//this unit test great
			std::string s = n->PostOrder();
			std::string t = "60, 50, 75, 150, 99, 65";
			Assert().AreEqual(t, s);
			delete n;
		}
		
		TEST_METHOD(AddDeleteTest)
		{
			Node<int>* n = new Node<int>(1);
			n = n->Add(2);
			n = n->Add(3);
			n = n->Add(4);
			n = n->Add(5);
			
			Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
			n = n->Remove(5, n);
			Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
			n = n->Remove(4, n);
			Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
		
			n = n->Remove(3, n);
			Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
			
			n = n->Remove(2, n);
			Assert().IsTrue(n->left->Height() - n->right->Height() <= 1 && n->left->Height() - n->right->Height() >= -1);
			
			n = n->Remove(1, n);
			Assert().IsNull(n);
			delete n;
		}
		
	};
}
