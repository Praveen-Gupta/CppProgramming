#include "BinaryTree.h"
#include <iostream>

int main()
{
	BinaryTree MyTree;

	/* Tree look like as below
				100
         50            200
       1    60      180       400
    -1   40      150   250
		 */

	MyTree.AddMultipleNode({100,50,200,1,-1,400,180,40,60,150,250});
	MyTree.LevelOrderLineByLine(MyTree.m_pRoot);
	
	return 0;
}

