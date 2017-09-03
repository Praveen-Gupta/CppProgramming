#pragma once

#include <iostream>
#include<vector>

#include "Node.h"


class BinaryTree
{
public:
	Node* m_pRoot;

public:
	BinaryTree() : m_pRoot(nullptr)
	{}

	virtual ~BinaryTree()
	{
		DeleteNodes(m_pRoot);
	}

	int height(Node* node)
	{
		if (!node)
			return 0;
		else
		{
			int LHeight = height(node->pLeft);
			int RHeight = height(node->pRight);
			if (LHeight > RHeight)
				return LHeight + 1;
			else
				return RHeight + 1;
		}
	}


	void Visit(const Node * CurNode) const
	{
		std::cout << CurNode->nData << std::endl;
	}

	void InOrder(const Node* node) const
	{
		if (node)
		{
			InOrder(node->pLeft);
			Visit(node);
			InOrder(node->pRight);
		}
	}

	void PreOrder(const Node* node) const
	{
		if (node)
		{
			Visit(node);
			PreOrder(node->pLeft);
			PreOrder(node->pRight);
		}
	}

	void Postorder(const Node* node) const
	{
		if (node)
		{
			Postorder(node->pLeft);
			Postorder(node->pRight);
			Visit(node);
		}
	}

	bool AddNode(int nData)
	{
		if (!m_pRoot)
		{
			AddRoot(nData);
			return true;
		}

		Node* CurNode = m_pRoot;
		Node* NewNode = new Node(nData);
		bool bAdded = false;
		while (!bAdded)
		{
			if (CurNode->nData > nData)
			{
				if ((CurNode->pLeft))
				{
					CurNode = CurNode->pLeft;
				}
				else
				{
					CurNode->pLeft = NewNode;
					bAdded = true;
				}
			}
			else
			{
				if (CurNode->pRight)
				{
					CurNode = CurNode->pRight;
				}
				else
				{
					CurNode->pRight = NewNode;
					bAdded = true;
				}
			}
		}

		return bAdded;
	}

	/**************************************************************************
	* Helper Function to Add Multiple nodes at one
	* Usage : 	MyTree.AddMultipleNode({100,50,200,1,-1,400,180,40,60,150,250});
	**************************************************************************/

	bool AddMultipleNode(const std::vector <int> & vData)
	{
		bool bSuccess = true;
		for each(int i in vData)
		{
			bSuccess&= AddNode(i);
		}
		return bSuccess;
	}

private:

	void AddRoot(int nData)
	{
		m_pRoot = new Node(nData);

		m_pRoot->nData = nData;
		m_pRoot->pLeft = nullptr;
		m_pRoot->pRight = nullptr;
	}

	void DeleteNodes(Node* node)
	{
		if (node)
		{
			DeleteNodes(node->pLeft);
			DeleteNodes(node->pRight);
			delete node;
		}
	}
};
