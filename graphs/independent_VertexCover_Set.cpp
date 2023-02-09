#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct BinaryTree{
	int val , MIS, mVC;
	BinaryTree *left, *right;
}*Bptr;

Bptr getNewnode(){
	Bptr newnode = new BinaryTree;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->MIS = -1;
	newnode->mVC = -1;
	return newnode;
}

void print(Bptr root){
	if (root)
	{
		print(root->left);
		cout<<" { "<<root->val<<" ,"<<root->MIS<<", "<<root->mVC<<", } ";
		print(root->right);
	}
}
void insert(Bptr &root , int key){
	if (root == NULL)
	{
		root = getNewnode();
		root->val = key;
	}
	else if(root->val < key)
		insert(root->right , key);
	else
		insert(root->left, key);
}

int max( int a, int b){
	if( a>b) return a;
	return b;
}
int min( int a, int b){
	if( a<b) return a;
	return b;
}

int maxIndependentSet(Bptr &root){

	if(root == NULL)	return 0;

	if(root->MIS != -1)	return root->MIS;  // DP soln
	int exc_root = maxIndependentSet(root->left) + maxIndependentSet(root->right);

	int inc_root = 1;
	if(root->left)
		inc_root += maxIndependentSet(root->left->left) + maxIndependentSet(root->left->right);
	if(root->right)
		inc_root += maxIndependentSet(root->right->left) + maxIndependentSet(root->right->right);

	root->MIS =  max(inc_root , exc_root);
	return root->MIS;

}

int minVertexCover(Bptr &root){
	if (root == NULL) return 0;
	if( root->left == NULL && root->right == NULL) return 0;

	if(root->mVC != -1) return root->mVC;		// DP soln

	int inc_root = 1 + minVertexCover(root->left) + minVertexCover(root->right);

	int exc_root = 0;
	if(root->left)
		exc_root += 1 + minVertexCover(root->left->left) + minVertexCover(root->left->right);
	if(root->right)
		exc_root += 1 + minVertexCover(root->right->left) + minVertexCover(root->right->right);
	
	root->mVC = min(inc_root , exc_root);
	return root->mVC;
}

int main(int argc, char const *argv[])
{
	Bptr root = NULL;
	// cout<<root<<endl;

	int arr[] = {60,20,10,40,30,50,70,80};
	int i = 0;
	int size = sizeof(arr)/ sizeof(arr[0]);
	while(i<size){
		insert(root, arr[i]);
		i++;
	}
	print(root);
	cout<<"\nmaxIndependentSet -> "<<maxIndependentSet(root);
	print(root);


	cout<<"\nminVertexCover -> "<<minVertexCover(root);
	print(root);
	return 0;
}

