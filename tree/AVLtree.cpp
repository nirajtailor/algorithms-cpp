#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct AVLnode{
	int val , height;
	AVLnode *lchild, *rchild;
}*AVLptr;

AVLptr getNewnode(){
	AVLptr newnode = new AVLnode;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	return newnode;
}

void R_R(AVLptr &T){
	AVLptr temp = T->lchild;
	T->lchild = temp->rchild;
	temp->rchild = T;

	int lh = -1, rh = -1;

	if(T->lchild) lh = T->lchild->height;
	if(T->rchild) rh = T->rchild->height;

	T->height = (lh > rh ? lh  : rh ) + 1;

	lh = -1;
	if(temp->lchild) lh = temp->lchild->height;
	rh = T->height;

	temp->height = (lh > rh ? lh  : rh ) + 1;

	T = temp;
}

void L_L(AVLptr &T){
	AVLptr temp = T->rchild;
	T->rchild = temp->lchild;
	temp->lchild = T;

	int lh = -1, rh = -1;

	if(T->lchild) lh = T->lchild->height;
	if(T->rchild) rh = T->rchild->height;

	T->height = (lh > rh ? lh  : rh ) + 1;

	lh = T->height;
	rh = -1;
	if(temp->rchild) rh = temp->rchild->height;

	temp->height = (lh > rh ? lh  : rh ) + 1;

	T = temp;

}

void L_R(AVLptr &T){
	L_L(T->lchild);
	R_R(T);
}

void R_L(AVLptr &T){
	R_R(T->rchild);
	L_L(T);
}
void insert(AVLptr &root , int key){
	if(root == NULL){
		root = getNewnode();
		root->val = key;
		root->height = 0;
	}
	else if(root->val > key){
		insert(root->lchild , key);
	}
	else {
		insert(root->rchild, key);
	}

	int lh = -1, rh = -1;
	if(root->lchild) lh = root->lchild->height;
	if(root->rchild) rh = root->rchild->height;

	if(lh - rh == 2){
		if(root->lchild->val > key) {
			R_R(root);
		}
		else{
			L_R(root);
		}
	}
	else if(rh - lh == 2){
		if(root->rchild->val < key){
			L_L(root);
		}
		else {
			R_L(root);
		}
	}
	else
	root->height = (lh > rh ? lh  : rh ) + 1;

}

int height(AVLptr &root){
	if(root == NULL) return -1;
	int l_height = height(root->lchild);
	int r_height = height(root->rchild);
	return l_height > r_height ? l_height + 1 : r_height + 1;
}

void print(AVLptr &root){
	if(root == NULL) return;

	if(root->lchild){
		print(root->lchild);
	}
	cout<<"[ "<<root->val<<", "<<root->height<<" ] ";

	if(root->rchild){
		print(root->rchild);
	}
}

int main(int argc, char const *argv[])
{
	
	AVLptr root = NULL;
	int arr[] = {34,31,52,2,5,24,64,89};
	int i=0, n = sizeof(arr)/sizeof(arr[0]);

	while(i < n){
		insert(root, arr[i++]);
		print(root);
		cout<<endl;
		cout<<height(root)<<endl;
	}
	

	return 0;
}