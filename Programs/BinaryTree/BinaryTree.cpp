#include  "BinaryTree.h"
#include <queue>


int BinaryTree::Height(const Node* node) const
{
	if (!node)
		return 0;
	else
	{
		int LHeight = Height(node->pLeft);
		int RHeight = Height(node->pRight);
		if (LHeight > RHeight)
			return LHeight + 1;
		else
			return RHeight + 1;
	}
}

/******************************************************************************
* Level Order Tree Traversal : Level order traversal of a tree is breadth first traversal for the tree.
* http://www.geeksforgeeks.org/level-order-tree-traversal/
******************************************************************************/
void BinaryTree::LevelOrder(const Node * node) const
{
	std::queue <const Node*> qNodes;
	qNodes.push(node);

	while (!qNodes.empty())
	{
		Visit(qNodes.front());
		const Node* CurrNode = qNodes.front();
		qNodes.pop();
		if (CurrNode->pLeft)
			qNodes.push(CurrNode->pLeft);
		if (CurrNode->pRight)
			qNodes.push(CurrNode->pRight);
	}
}

/******************************************************************************
* Print level order traversal line by line | Set 1
* http://www.geeksforgeeks.org/print-level-order-traversal-line-line/
******************************************************************************/
void BinaryTree::LevelOrderLineByLine(const Node * node) const
{
	std::queue <const Node*> qNodes;
	qNodes.push(node);

	while (true)
	{
		size_t nLevelNodeCount = qNodes.size();
		if (0 == nLevelNodeCount)
			break;
		while (0 != nLevelNodeCount)
		{
			std::cout << qNodes.front()->nData << " ";
			const Node* CurrNode = qNodes.front();
			qNodes.pop();
			if (CurrNode->pLeft)
				qNodes.push(CurrNode->pLeft);
			if (CurrNode->pRight)
				qNodes.push(CurrNode->pRight);
			nLevelNodeCount--;
		}
		std::cout << std::endl;
	}
}

