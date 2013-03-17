/*
 * Casey Miles
 * EECS 560
 * Lab 7
 *
 * treeNode.cpp
 * Contains function code for TreeNode class
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "treeNode.h"


////////////////////////////////////////
//    Constructors and Destructors    //
////////////////////////////////////////

TreeNode::TreeNode(int num){
	item = num;
	leftChild = NULL;
	rightChild = NULL;
}

TreeNode::~TreeNode(){
	leftChild = NULL;
	rightChild = NULL;
	item = 0;
}


////////////////////////////////////////
//            Other Functions         //
////////////////////////////////////////

/*
 * Inserts a new node into the tree by performing
 * binary search until the correct position is found.
 */
void TreeNode::insert(int x){

	if(x < item){			//i.e., try inserting in left subtree
		if(leftChild == NULL){		//create a new node and connect it
			TreeNode *nodeToInsert = new TreeNode(x);
			leftChild = nodeToInsert;
		}
		else {				//the left child is not null, so try to insert in THAT tree
			leftChild->insert(x);
		}
	}
	else {					//i.e., x > item; try inserting in the right subtree
		if(rightChild == NULL){
			TreeNode *nodeToInsert = new TreeNode(x);
			rightChild = nodeToInsert;
		}
		else {
			rightChild->insert(x);
		}
	}


}

/*
 * Removes an item from the tree by performing binary search
 * until the item is found. Then, if the item has only one child,
 * it is replaced by that child. If the item has two children,
 * it is replaced by the smallest child in the right subtree.
 */
TreeNode *TreeNode::remove(int x){

	switch(x == item){		//Check to see that we've actually found the item
		case true:			//If we have found the item, try to remove it
			//Case where node has no children
			if((leftChild == NULL) && (rightChild == NULL)){
				return NULL;
			}
			//Case where there is only a left child
			else if ((leftChild != NULL) && (rightChild == NULL)){

				TreeNode *nodeToReturn = leftChild;
				delete this;

				return nodeToReturn;
			}
			//Case where there is only a right child
			else if ((leftChild == NULL) && (rightChild != NULL)){

				TreeNode *nodeToReturn = rightChild;
				delete this;

				return nodeToReturn;
			}
			//Case where there are two children
			else {
				//Replace this node's item with the smallest item in right subtree
				this->item = rightChild->getmin();
				//Now delete the node that we just copied from
				this->rightChild = rightChild->deletemin();
				return this;
			}
			break;
		case false:			//If we haven't yet found the item, continue searching
			if(x < item){
				if(leftChild != NULL)
					leftChild = leftChild->remove(x);
				else
					cout << x << " not found in tree. TRY AGAIN" << endl;
			}
			else {
				if(rightChild != NULL)
					rightChild = rightChild->remove(x);
				else
					cout << x << " wasn't found in the tree. TRY AGAIN" << endl;
			}
			break;
	}

}

/*
 * Searches for the leftmost node. When that is found,
 * this function returns the right child, whether or not it's empty
 */
TreeNode *TreeNode::deletemin(){

	if(leftChild == NULL){
		TreeNode *nodeToReturn = rightChild;
		delete this;
		return nodeToReturn;
	}
	else {		//Keep looking for the leftmost node
		leftChild = leftChild->deletemin();
	}
}

/*
 * Searches for the leftmost node. When that is found,
 * return the integer contained in that node.
 */
int TreeNode::getmin(){

	if(leftChild == NULL){
		return this->item;
	}
	else {
		return leftChild->getmin();
	}
}	

/*
 * Search for the rightmost node and delete it.
 */
TreeNode *TreeNode::deletemax(){

	if(rightChild == NULL){
		TreeNode *nodeToReturn = leftChild;
		delete this;
		return nodeToReturn;
	}
	else {		//Keep looking for the rightmost node
		rightChild = rightChild->deletemax();
	}

}

/*
 * Print out all the nodes in the tree in this order:
 * Root, Left Subtree, Right Subtree
 */
void TreeNode::preorder(){

	//Print the item contained in the "root" node
	cout << item << " ";

	//Then print the left subtree in preorder
	if(leftChild != NULL)
		leftChild->preorder();

	//Then print the right subtree in preorder
	if(rightChild != NULL)
		rightChild->preorder();

}

/*
 * Print out all the nodes of the tree in this order:
 * Left Subtree, Root, Right Subtree
 */
void TreeNode::inorder(){
	//First print the items in the left subtree
	if(leftChild != NULL)
		leftChild->inorder();

	//Then print the item contained in the root
	cout << item << " ";

	//Then print the items in the right subtree
	if(rightChild != NULL)
		rightChild->inorder();

}
