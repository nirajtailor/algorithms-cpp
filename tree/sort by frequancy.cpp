#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// method - I

bool fun( pair < int , pair < int , int > > a, 
	pair < int , pair < int , int > > b){
	if( a.second.second != b.second.second){
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first < b.second.first;
	}
}

void sortByFrequency(int arr[] , int n){

	unordered_map< int , pair < int , int > > hash;

	for( int i =0; i < n ; i++){
		if(hash.find(arr[i]) != hash.end()){
			hash[arr[i]].second++;
		}
		else{
			hash[arr[i]] = make_pair(i,1);
		}
	}
	
	vector< pair < int, pair<int , int> > > vlist;
	int i =0;
	for (auto it = hash.begin(); it != hash.end() ; it++){
		cout<<"\n"<<it->first<<", :";
		cout<<it->second.first<<", "<<it->second.second<<" ->";

		vlist.push_back(make_pair(it->first , it->second)); // pushing value and pair
		cout<<vlist[i].first<<" , ";
		cout<<vlist[i].second.first<<" , "<<vlist[i++].second.second<<endl;
	}
	sort(vlist.begin() , vlist.end() , fun);

	for (auto it = vlist.begin(); it != vlist.end() ; it++){
		cout<<it->first<<" : ";
		cout<<it->second.second<<" at "<<it->second.first<<endl;
	}
}

// method - II

typedef struct BSTnode
{
	struct BSTnode *left , *right;
	int index , count , key;
}*BSTptr;

BSTptr getBSTnode(){
	BSTptr T = new BSTnode;
	T->key = -1;
	T->count = -1;
	T->left = NULL;
	T->right = NULL;

	return T;
}

void insertBST(BSTptr &root , int key , int index){
	if(root == NULL){
		root = getBSTnode();
		root->key = key;
		root->index = index;
		root->count = 1;
		return ;
	}

	if(root->key == key){
		root->count++;
		return;
	}
	else if( key < root->key){
		insertBST(root->left , key , index);
	}
	else{
		insertBST(root->right, key , index);
	}

}

void printBST(BSTptr root){
	if(root == NULL) return;
	if(root->left) printBST(root->left);
	cout<<root->key<<" , "<<root->count<<" , "<<root->index<<endl;
	if(root->right) printBST(root->right);
}

void BSTsort(int arr[] , int n){
	BSTptr root = NULL;
	int i=0;
	while(i<n){
		insertBST(root , arr[i] , i);
		i++;
	}
	printBST(root);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,4,5,6,4,5,5,4,7,8,8,8,6,6,4,4,3};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		cout<<arr[i]<<", ";
	}

	sortByFrequency(arr, sizeof(arr)/sizeof(arr[0]));

	BSTsort(arr, sizeof(arr)/sizeof(arr[0]));

	int i =0;
	cout<<" num "<< i++ << i+1 << i++ <<endl;
	return 0;
}