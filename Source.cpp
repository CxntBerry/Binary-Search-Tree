#include <iostream>

//Simple Binary Search Tree

//Everything to the right node is higher

//Take one number in = root node

class Node {
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
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
			std::cout << CurrentNode->data << " > "; // Output steps
		}
		else
		{
			Node* Left = new Node;
			Left->data = Data; // Set the data of the current node
			Root->left = Left; // Set the data of the current node
			Left->parent = Root; // Set the parent of current node as the previous node
			std::cout << "\nNew Node " << Data << " Left of << " << Root->data << std::endl;
			return; // Exit the loop
		}
	}
	else {
		if (Root->right != nullptr)
		{
			Create(Data, Root->right); // Continue
			std::cout << CurrentNode->data << " > "; // Output steps
		}
		else
		{
			Node* Right = new Node;
			Right->data = Data; // Set the data of the current node
			Root->right = Right; // Set the previous node->right to the current node
			Right->parent = Root; // Set the parent of current node as the previous node
			std::cout << "\nNew Node " << Data << " Right of << " << Root->data << std::endl;
			return; // Exit the loop
		}
	}
}

Node* Search(int Data, Node* Root)
{
	Node* CurrentNode = new Node;
	CurrentNode->data = Data;
	if (CurrentNode->data < Root->data)
	{
		if (Root->left == nullptr)
		{
			std::cout << "\nNot Found, nearest data: " << Root->data << std::endl;
			return Root;
		}
		else {
			std::cout << Root->data << ">";
			Search(Data, Root->left);
		}
	}
	if (CurrentNode->data > Root->data)
	{
		if (Root->right == nullptr)
		{
			std::cout << "\nNot Found, nearest data: " << Root->data << std::endl;
			return Root;
		}
		else {
			std::cout << Root->data << ">";
			Search(Data, Root->right);
		}
	}
}

void Sort(Node* Root)
{

}


void Delete(int Data, Node* Root)
{
	// If Leaf node: Delete
	// If node has one child: Move child up to take its place
	// If the node has two children: Replace the nodes value with the maximum value from its left subtree (and then delete that maximum value from that left subtree
	Node* NodeToDelete = Search(Data, Root);
	Node* PreviousNode = NodeToDelete->parent;
	Node* NodeToDeleteLeft = NodeToDelete->left;
	Node* NodeToDeleteRight = NodeToDelete->right;
	if (NodeToDeleteLeft == nullptr || NodeToDeleteRight == nullptr) // Leaf node: Delete
	{
		delete NodeToDelete;
	}
	if (NodeToDeleteLeft != nullptr) // Check for one child, if only one child delete, otherwise call function again
	{
		if (NodeToDeleteRight != nullptr)
		{
			Delete(Data, Root);
		}
		if (PreviousNode->left == NodeToDelete)
		{
			PreviousNode->left == NodeToDeleteLeft;
		}
		if (PreviousNode->right == NodeToDelete)
		{
			PreviousNode->right == NodeToDeleteLeft;
		}
		delete NodeToDelete;
	}
	if (NodeToDeleteRight != nullptr) // Same as previous statement
	{
		if (NodeToDeleteLeft != nullptr)
		{
			Delete(Data, Root);
		}
		if (PreviousNode->left == NodeToDelete)
		{
			PreviousNode->left = NodeToDeleteRight;
		}
		if (PreviousNode->right = NodeToDelete)
		{
			PreviousNode->right = NodeToDeleteRight;
		}
		delete NodeToDelete;
	}
	if (NodeToDeleteRight != nullptr | NodeToDeleteLeft != nullptr)
	{
		PreviousNode->left = NodeToDeleteLeft;
		delete NodeToDelete;
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
	for (int f = 0; f < 4; f++)
	{
		std::cout << "Please search for a number:\n\n";
		std::cin >> userInput;
		Search(userInput, Head);
	}
	std::cout << "\nPlease type a node to delete" << std::endl;
	std::cin >> userInput;
	Delete(userInput, Head);
	std::cout << "Enter the child of the number you deleted: ";
	std::cin >> userInput;
	Search(userInput, Head);
	getchar();
}