// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <windows.h>

#include "Node.h"
#include "AVLNode.h"


class BSTTests
{
public:
	BSTTests()
	{
		//this->huh = 1;
	}
	bool AddTest1()
	{
		Node<int>* n = new Node<int>(40);
		n->Add(50);
		n->Add(45);
		n->Add(35);
		n->Add(30);
		//std::cout << n->PostOrder();
		if (n->PostOrder() == "30 35 45 50 40")
		{
			std::cout << "AddTest1 Works (if PostOrder Tests dont work this may be unreliable)";
			return true;
		}
		return false;
		//n->Visualizer("", false);
	}
	//another add test
	
	bool AddTestBasic()
	{
		Node<int>* n = new Node<int>(40);
		n->Add(50);
		n->Add(45);
		n->Add(35);
		n->Add(30);
		//std::cout << n->PostOrder();
		if (n->PostOrder() == "30, 35, 45, 50, 40")
		{
			std::cout << "AddTest1 Works (if PostOrder Tests dont work this may be unreliable)" << std::endl;
			return true;
		}
		std::cout << n->PostOrder();
		//n->Visualizer("",false);
		return false;
		//n->Visualizer("", false);
	}
	//if add test basic works do other tests as Basic is the foundation that the thing even works

	//Actual Add tests
	bool AddTestEmpty()
	{
		Node<int>* n = new Node<int>();
		n->Add(100);
		if (n->value == 100)
		{
			std::cout << "AddTest2 Works" << std::endl;
			return true;
		}
		return false;
	}

	bool AddTestDupe()
	{
		//should just return without adding nothing
		Node<int>* n = new Node<int>(5);
		n->Add(2);
		n->Add(3);
		n->Add(3);
		if (n->InOrder() == "2, 3, 5")
		{
			std::cout << "AddTest3 Works" << std::endl;
			return true;
		}
		else { 
			std::cout << n->InOrder();
			return false; }
	}

	//Contains tests

	bool ConatinTestEmpty()
	{
		Node<int>* n = new Node<int>();

		std::cout << "ContainTestEmpty" << std::endl;
		n->Visualizer();
		return !n->Contains(5);
	}
	bool ContainTestLarge()
	{
		Node<int>* n = new Node<int>(500);
		int y;
		for (int x = 0; x < 150; x++)
		{
			int num = rand();
			n->Add(num);
			if (x == 145) {
				y = num;
			}
		}
		std::cout << "ContainTestLarge" << std::endl;
		//n->Visualizer();
		//std::cout << y << std::endl;
		return n->Contains(y);


	}

	//Removes Tests
	bool RemoveTestNoExist()
	{
		Node<int>* n = new Node<int>(50);
		n->Add(150);
		n->Add(25);
		n->Add(12);
		n->Add(200);
		std::string before = "12, 25, 200, 150, 50";
		n->Remove(55,n);
	//	n->Remove(45,n);

		std::cout << "RemoveTestNoExist" << std::endl;
		std::cout << before << std::endl;
		std::cout << n->PostOrder() << std::endl;
		//n->Visualizer();
		return true;

	}

	bool RemoveTestRootRemove()
	{
		Node<int>* test = new Node<int>(30);
		test->Add(25);
		test->Add(15);

		Node<int>* n = new Node<int>(26);
		n->Add(25);
		n->Add(15);
		n->Add(30);

		n->Remove(26,n);

		std::cout << "RemoveTestRootRemove" << std::endl;
		std::cout << n->PostOrder() << std::endl;
		std::cout << test->PostOrder() << std::endl;
		n->Visualizer();
		return n->PostOrder() == test->PostOrder();
	}

	//Clear tests?

	bool ClearTest()
	{
		Node<int>* n = new Node<int>(26);
		n->Add(25);
		n->Add(15);
		n->Add(30);

		n->Clear(n);

		std::cout << "Cleartest" << std::endl;
		//std::cout << n->PostOrder() << std::endl;
		return !n;

	}

	//Count Test

	bool CountTestEmpty()
	{
		Node<int>* n = new Node<int>();
		std::cout << "CountTestEmpty" << std::endl;
		return n->Count() == 1;
	}
	bool CountTest()
	{
		Node<int>* n = new Node<int>(50);
		std::cout << "CountTest" << std::endl;
		n->Add(25);
		n->Add(75);

		return n->Count() == 3;
	}

	//Height test

	bool HeightTestBalanced()
	{
		Node<int>* n = new Node<int>(50);
		n->Add(25);
		n->Add(75);
		std::cout << "HeightTest" << std::endl;
		return n->Height() == 2;
	}
	bool HeightTestUnbalanced()
	{
		Node<int>* n = new Node<int>(50);
		n->Add(25);
		n->Add(75);
		n->Add(60);
		n->Add(65);
		std::cout << "HeightTestUnbalanced" << std::endl;
		return n->Height() == 4;
	}

	//ToArray Tests

	bool ToArrayTest()
	{
		Node<int>* n = new Node<int>(9);
		n->Add(8);
		n->Add(12);
		n->Add(11);
		n->Add(7);
		n->Add(5);
		n->Add(1);
		int test[] = {
			1,5,7,8,9,11,12
		};
		std::cout << "ToArraytest" << std::endl;
		std::cout << std::to_string(n->ToArray()[0]) + std::to_string(n->ToArray()[1]) + std::to_string(n->ToArray()[2]) + std::to_string(n->ToArray()[3]) + std::to_string(n->ToArray()[4]) + std::to_string(n->ToArray()[5]) + std::to_string(n->ToArray()[6]);
		return n->ToArray() == test;
	}
	bool ToArrayTestEmpty()
	{
		Node<int>* n = new Node<int>();
		int test[1] = {};
		std::cout << "ToArrayEmpty" << std::endl;
		//s//td::cout << n->ToArray();
		return !n->ToArray();
	}

	//Basic Order Tests
	bool InTestBasic()
	{
		Node<int>* n = new Node<int>(9);
		n->Add(8);
		n->Add(12);
		n->Add(11);
		std::cout << "InTest" << std::endl;
		std::cout << n->InOrder();
		return n->InOrder() == "8, 9, 11, 12";
	}
	bool InTestEmpty()
	{
		Node<int>* n = new Node<int>();
		std::cout << "InTestEmpty" << std::endl;
	//	std::cout << n->InOrder();
		return n->InOrder() == "00";
	}

	bool PreTestBasic()
	{
		Node<int>* n = new Node<int>(9);
		n->Add(8);
		n->Add(12);
		n->Add(11);
		std::cout << "PreTestBasic" << std::endl;
		std::cout << n->PreOrder();
		return n->PreOrder() == "9, 8, 12, 11";
	}
	bool PreTestPostTestOneNode()
	{
		Node<int>* n = new Node<int>(9);
		std::cout << "PreTestPostTestOne" << std::endl;
		return n->PostOrder() == n->PreOrder();
	}
	bool PreTestPostTestNotMatch()
	{
		Node<int>* n = new Node<int>(9);
		n->Add(8);
		n->Add(12);
		n->Add(11);
		std::cout << "PreTestPostTest" << std::endl;
		return n->PostOrder() != n->PreOrder();
	}
	bool PostTestBasic()
	{
		Node<int>* n = new Node<int>(9);
		n->Add(8);
		n->Add(12);
		n->Add(11);
		std::cout << "PostTest" << std::endl;
		return n->PostOrder() == "8, 11, 12, 9";
	}


private:
	int huh = 0;
};


int main()
{
	/*Node<int>* n = new Node<int>(40);
	n->Add(50);
	n->Add(45);
	n->Add(35);
	n->Add(30);
	std::cout << n->PostOrder();*/
	/*BSTTests* b = new BSTTests();*/
	
	/*if (b->AddTestBasic())
	{
		std::cout << b->AddTestEmpty() << std::endl;
		std::cout << b->AddTestDupe() << std::endl;
		std::cout << b->ConatinTestEmpty() << std::endl;
		std::cout << b->ContainTestLarge() << std::endl;
		std::cout << b->RemoveTestRootRemove() << std::endl;
		std::cout << b->RemoveTestNoExist() << std::endl;
		std::cout << b->ClearTest() << std::endl;
		std::cout << b->CountTest() << std::endl;
		std::cout << b->CountTestEmpty() << std::endl;
		std::cout << b->HeightTestBalanced() << std::endl;
		std::cout << b->HeightTestUnbalanced() << std::endl;
		std::cout << b->ToArrayTest() << std::endl;
		std::cout << b->ToArrayTestEmpty() << std::endl;
		std::cout << b->InTestBasic() << std::endl;
		std::cout << b->InTestEmpty() << std::endl;
		std::cout << b->PreTestBasic() << std::endl;
		std::cout << b->PreTestPostTestNotMatch() << std::endl;
		std::cout << b->PreTestPostTestOneNode() << std::endl;
		std::cout << b->PostTestBasic() << std::endl;
		std::cout << "if all 1s i've won";

	}
	else {
		std::cout << "I lose outright ;(";
	}*/

	Node<int>* n = new Node<int>(40);
	n = n->Add(50);
	//n->Visualizer();
	std::cout << n->Height();
	std::cout << std::endl;
	std::cout << n->right->Height();
	std::cout << std::endl;
	//std::cout << n->right->value;
	std::cout << std::endl;
	
	std::cout << n->PostOrder();
	n=n->Add(45);
	std::cout << std::endl;
	
//	n->Visualizer();
	std::cout << std::endl;
	std::cout << n->PostOrder();

	//Node<int>* n2 = new Node<int>(45);
	//n = n->Add(50);
	//n = n->Add(40);
	//std::cout << std::endl;
	//std::cout << n->PostOrder();

	Node<int>* n2 = new Node<int>(40);
	n2 = n2->Add(30);
	std::cout << std::endl;
	std::cout << n2->PostOrder();
	n2 = n2->Add(35);
	std::cout << std::endl;
	std::cout << n2->PostOrder();


	Node<int>* n4 = new Node<int>(40);
	n4 = n4->Add(50);
	n4 = n4->Add(60);

	Node<int>* n5 = new Node<int>(50);
	n5 = n5->Add(40);
	n5 = n5->Add(60);

	std::string s = n4->PostOrder();
	std::string t = n5->PostOrder();
	std::cout << std::endl;
	std::cout << s;
	std::cout << std::endl;
	std::cout << t;

	Node<int>* n6 = new Node<int>(99);
	n6 = n6->Add(150);
	n6 = n6->Add(50);
	n6 = n6->Add(75);
	n6 = n6->Add(65);
	//n6 = n6->Add(60);
	std::cout << std::endl;
	std::cout << n6->PostOrder();
	std::cout << std::endl;
	std::cout << std::endl;

	Node<int>* n7 = new Node<int>((rand() % (300 - 1 + 1)) + 1);
	for (int a = 0; a < 200; a++)
	{
		n7 = n7->Add((rand()% (300-1+1))+1);
	}
	n7->Visualizer();
//	n6->Visualizer();
	//Assert().AreEqual(t, s);
	
	//std::cout << n->balanceFactor;
	//std::cout << 

}

//test methods for Node Class
//2 for each method




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln f