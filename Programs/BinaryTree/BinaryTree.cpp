#include "BinaryTree.h"
#include <iostream>

int main()
{
	BinaryTree MyTree;

	MyTree.AddMultipleNode({100,50,200,1,-1,400,180,40,60,150,250});

	std::cout << MyTree.height(MyTree.m_pRoot) << std::endl;

	MyTree.PreOrder(MyTree.m_pRoot);

	return 0;
}

