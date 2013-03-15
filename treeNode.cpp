/*
 * Casey Miles
 * EECS 560
 * Lab 7
 *
 * treeNode.cpp
 * Contains funciton code for TreeNode class
 */

#include <iostream>
#include <stdlib>

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
}


////////////////////////////////////////
//            Other Functions         //
////////////////////////////////////////

void TreeNode::insert(int x){
	//DO SOMETHING
}

void TreeNode::remove(int x){
	//DO SOMETHING
}

void TreeNode::deletemin(){
	//DO SOMETHING
}

void TreeNode::deletemax(){
	//DO SOMETHING
}

void TreeNode::preorder(){
	//PRINT SOMEHTING
}

void TreeNode::inorder(){
	//PRINT SOMETHING
}
