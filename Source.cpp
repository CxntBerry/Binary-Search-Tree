#include <iostream>

//Simple Binary Search Tree

//Everything to the right node is higher

//Take one number in = root node

class Node {
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

void Create(int Data, Node* Root)
{
	Node* CurrentNode = new Node;
	CurrentNode->data = Data;
	if (CurrentNode->data < Root->data)
	{
		if (Root->left != nullptr)
		{
			Create(Data, Root->left);
			std::cout << Data << " > ";
		}
		else
		{
			Node* Left = new Node;
			Left->data = Data;
			CurrentNode->left = Left;
			std::cout << "\nNew Node " << Data << " Left of << " << Root->data << std::endl;
			return;
		}
	}
	else {
		if (Root->right != nullptr)
		{
			Create(Data, Root->right);
			std::cout << CurrentNode->data << " > ";
		}
		else
		{
			Node* Right = new Node;
			Right->data = Data;
			CurrentNode->right = Right;
			std::cout << "\nNew Node " << Data << " Right of << " << Root->data << std::endl;
			return;
		}
	}
}



//Create Headnode
//In for loop do while loop
//if < and currentNode->left == nullptr
//set variable root to current root
//Next iteration of while loop will be in that position


//Return Steps to get operation
int main()
{
	//take 10 numbers; store in tree
	std::cout << "Please enter 10 numbers" << std::endl;
	int userInput;
	int firstInput;
	std::cin >> firstInput;
	Node* Head = new Node;
	Head->data = firstInput;
	std::cout << "First node: " << Head->data << std::endl;
	for (int i = 0; i < 9; i++)
	{
		std::cin >> userInput;
		Create(userInput, Head);
	}
	getchar();
}