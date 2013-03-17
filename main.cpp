#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;

#include "treeNode.h"

int main( const int argc, const char * argv[]){

	TreeNode	*tree;
	ifstream	inFile;
	int			valueFromFile;

	if (argc < 2){
		cout << "Usage: ./bst <filename>" << endl;
		return 1;
	}

	inFile.open(argv[1]);

	//Get the first item and
	//create the root of the tree.
	inFile >> valueFromFile;
	tree = new TreeNode(valueFromFile);

	//Continue reading integers until the end of the file
	//and insert each integer into the tree as it's read
	while(inFile >> valueFromFile){
		tree -> insert(valueFromFile);
	}

	cout << "Tree after initial insertion: ";
	tree -> preorder();
	cout << endl;

	cout << "Deleting min, max, 7 from tree. " << endl;
	tree -> deletemin();
	tree -> deletemax();
	tree -> remove(7);

	cout << "Tree after deletions: ";
	tree -> preorder();
	cout << endl;


	cout << "Applying insert(2) insert(17) insert(11) insert(16) insert(18)" << endl;
	tree -> insert(2);
	tree -> insert(17);
	tree -> insert(11);
	tree -> insert(16);
	tree -> insert(18);
	cout << "Tree after second insertions: ";
	tree -> preorder();
	cout << endl << endl;

	cout << "Applying remove(6) remove(10) remove(13)" << endl;
	tree -> remove(6);
	tree -> remove(10);
	tree -> remove(13);
	cout << "Preorder: ";
	tree -> preorder();
	cout << endl;
	cout << "Inorder: ";
	tree -> inorder();
	cout << endl;

	return 0;
	

}
