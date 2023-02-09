
// B tree with key 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int k = 1;
typedef struct  BDTREEnode{
	int count ;
	int key[2*k+1];
	struct  BDTREEnode *ptr[2*k+2];
}*BDptr;

BDptr getNode(){
	BDptr newnode = new BDTREEnode;
	newnode->count = 0;
	for (int i = 0; i < 2*k+1; ++i)
		newnode->key[i] = -1;
	for (int i = 0; i < 2*k+2; ++i)
		newnode->ptr[i] = NULL;
	return newnode; // return or not
}

int insertInNode(BDptr &T, int val){
	int i = 0;
	// find position 
	for (i = 0; i < T->count; ++i){
		if(T->key[i] > val || T->key[i] == -1)
			break;
	}
	// shift right 
	for (int j = T->count; j>i; --j){
		T->key[j] = T->key[j-1];
		if(T->ptr[j])
		T->ptr[j+1] = T->ptr[j];
	}
	T->key[i] = val;
	T->count++;
	return i;
}

void left_distribution(BDptr T, int index){
	int l = index-1;
	int l_count = T->ptr[l]->count;
	int i_count = T->ptr[index]->count;

	// shift pointer to left
	T->ptr[l]->key[l_count] = T->key[index-1];
	T->ptr[l]->count++;
	T->key[index-1] = T->ptr[index]->key[0];

	T->ptr[l]->ptr[l_count+1] = T->ptr[index]->ptr[0];

	for(int i=1 ; i< i_count ; i++){
		T->ptr[index]->key[i-1] = T->ptr[index]->key[i];
		T->ptr[index]->ptr[i-1] = T->ptr[index]->ptr[i];
	}
	T->ptr[index]->ptr[i_count-1] = T->ptr[index]->ptr[i_count];
	T->ptr[index]->ptr[i_count] = NULL;
	T->ptr[index]->key[i_count-1] = -1;
	T->ptr[index]->count--;
}

void right_distribution(BDptr &T, int index){
	int r = index + 1;
	int r_count = T->ptr[r]->count;
	int i_count = T->ptr[index]->count;
	//right shift keys and pointers in right node
	for(int i = r_count; i>0; i--){
		T->ptr[r]->key[i] = T->ptr[r]->key[i-1];
		T->ptr[r]->ptr[i+1] = T->ptr[r]->ptr[i];
	}
	T->ptr[r]->ptr[1] = T->ptr[r]->ptr[0];

	T->ptr[r]->key[0] =T->key[index];
	T->ptr[r]->count++;
	T->key[index] = T->ptr[index]->key[i_count-1];
	T->ptr[index]->key[i_count-1] = -1;
	T->ptr[index]->count--;
	// shift pointer to right node 
	T->ptr[r]->ptr[0] = T->ptr[index]->ptr[i_count];
	T->ptr[index]->ptr[i_count] = NULL;
}

void overflow(BDptr &T, BDptr &q){
	int midval = q->key[k];
	q->key[k] = -1;
	q->count--;
// copy right half values to new node p
	BDptr p = getNode();
	for (int i = 0; i < k; ++i){
		p->key[i] = q->key[k+1+i];
		q->key[k+1+i] = -1;
		p->ptr[i] = q->ptr[k+1+i];
		q->ptr[k+1+i] = NULL;
		p->count++;
		q->count--;
	}
	if(q->ptr[2*k+1]){
		p->ptr[k] = q->ptr[2*k+1];
		q->ptr[2*k+1] = NULL;
	}
	int i = insertInNode(T, midval);
	T->ptr[i+1] = p;
}

void addKey(BDptr &T, int val){
	if(T==NULL){
		T = getNode();
		T->key[0] = val;
		T->count = 1;
	}
	else if(T->ptr[0]){
		int i;
		for (i = 0; i < T->count ; ++i){
			if (T->key[i] > val || T->key[i] ==-1)
				break;
		}
		addKey(T->ptr[i] , val);
		// node over flow
		if(T->ptr[i]->count == 2*k+1){
			if(i > 0 && T->ptr[i-1]->count < 2*k){
				left_distribution(T, i);
				cout<<"\nleft_distribution\n";
			}
			else if(i < T->count && T->ptr[i+1]->count < 2*k){
				right_distribution(T, i);
				cout<<"\nright_distribution\n";
			}
			else{
				overflow(T, T->ptr[i]);
				cout<<"\noverflow\n";
			}
		}
	}
	else{
		insertInNode(T, val);
	}
}

void addUtil(BDptr &root, int val){
	cout<<"\n\nadd : "<<val<<endl;
	addKey(root, val);
	// root over flow
	if(root->count == 2*k+1){
		BDptr p = getNode();
		p->ptr[0] = root;
		overflow(p, root);
		root = p;
		cout<<"\nroot overflow\n";
	}
	// cout<<"root value "<<root->key[0];
	// cout<<" root count "<<root->count<<endl;
}

void printBDTree(BDptr root){
	queue<BDptr> Qptr;
	BDptr curr;
	Qptr.push(root);
	int n;
	cout<<"       ";
	while(!Qptr.empty()){
		n = Qptr.size();
		while(n--){
			curr = Qptr.front();
			Qptr.pop();
			if(curr == NULL)
				break;

			for(int i=0; i < curr->count; i++){
				cout<<":"<<curr->key[i];
				if(curr->ptr[i])
					Qptr.push(curr->ptr[i]);
			}
			if(curr->ptr[curr->count]){
				Qptr.push(curr->ptr[curr->count]);
			}
			for (int i = curr->count ; i<2*k+1 ; ++i){
				cout<<": ";
			}
			cout<<"      ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	
	BDptr root = NULL;
	int choose, data;
	cout<<"Welcome to BD tree program !!!\n";
	int arr[] = {100, 999, 600, 800, 500, 400,
					300, 700, 222, 555, 666, 333, 464, 964,
					345, 565};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	// addUtil(root, arr[0]);
	
	while(i<n){
		addUtil(root, arr[i++]);
		printBDTree(root);
	}
	// cout<<"root value "<<root->ptr[0]->key[1];
	// cout<<"root value "<<root->ptr[1]->key[1];
	return 0;
}