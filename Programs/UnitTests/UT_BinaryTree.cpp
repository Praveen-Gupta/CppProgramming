#include "CppUnitTest.h"
#include "..\BinaryTree\BinaryTree.h"

#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(BinaryTreeTests)
	{
	public:
		
		TEST_METHOD(BinaryTree_Height)
		{
			BinaryTree MyTree;
			MyTree.AddMultipleNode({ 100,50,200,1,-1,400,180,40,60,150,250 });
			assert(MyTree.height(MyTree.m_pRoot) == 4);
		}

	};
}