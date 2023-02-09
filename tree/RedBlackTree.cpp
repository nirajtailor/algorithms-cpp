#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
The AVL trees are more balanced compared to Red-Black Trees, 
but they may cause more rotations during insertion and deletion. 
So if your application involves many frequent insertions and deletions, 
then Red Black trees should be preferred. 
And if the insertions and deletions are less frequent and search is a more frequent operation, 
then AVL tree should be preferred over Red-Black Tree.

https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
*/
typedef struct RedBlacknode{
	int val ;
	bool color;   // 0 for red and 1 for black
	RedBlacknode *lchild, *rchild, *parent;
}*RBptr;

// todo

RBptr getNewnode(){
	RBptr newnode = new RedBlacknode;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->parent = NULL;
	return newnode;
}


void insert(RBptr &root , int key ){
	if(root == NULL){
		root = getNewnode();
		root->val = key;
	}
	else if(root->val > key){
		insert(root->lchild , key);
		root->lchild->parent = root;
	}
	else {
		insert(root->rchild, key);
		root->rchild->parent = root;
	}
}

void print(RBptr &root){
	if(root == NULL) return;

	if(root->lchild)
		print(root->lchild);

	cout<<root->val<<" ";
	if(root->rchild)
		print(root->rchild);

	if(root->parent)
		cout<<" P "<<root->parent->val<<" ";

}

int main(int argc, char const *argv[])
{
	RBptr root = NULL;
	int arr[] = {45,46,3,2,64,24,75,7,44};

	int i=0, n = sizeof(arr)/sizeof(arr[0]);
	while(i<n){
		insert(root, arr[i++]);
		print(root);
		cout<<endl;
	}
	return 0;
}