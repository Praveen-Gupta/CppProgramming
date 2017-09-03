#pragma once

class Node
{
private:
	int nData;
	Node* pLeft;
	Node* pRight;

	Node() = delete;
	Node(const Node&) = delete;
	Node(const Node &&) = delete;
	const Node& operator=(const Node &) = delete;

public:
	Node(int nInData) : nData(nInData), pLeft(nullptr), pRight(nullptr)
	{};

	friend class BinaryTree;
};
