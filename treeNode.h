/*
 * Casey Miles
 * EECS 560
 * Lab 7
 *
 * treeNode.h
 * Contains function declarations for the TreeNode class
 */

class TreeNode {

	public:
	TreeNode(int x);
	~TreeNode();

	int		item;
	TreeNode	*leftChild;
	TreeNode	*rightChild;

	void 		insert(int x);
	void		remove(int x);
	void		deletemin();
	void		deletemax();
	void		preorder();
	void		inorder();

};
