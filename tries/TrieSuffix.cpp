#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256

union pointer{
	struct TNode *bptr[MAX_CHAR];
	char *suffix;
};

typedef struct TNode{
	bool tag;
	union pointer u;
}*tptr;

tptr getTNode(){
	tptr newNode = new TNode;
	newNode->tag = 1;
	for (int i = 0; i < MAX_CHAR; ++i)
	{
		newNode->u.bptr[i] = NULL;
	}
	return newNode;
}

void appendNode(tptr &T, string word) {

	if (T == NULL)
	{
		T = new TNode;
		T->tag = 0;
		T->u.suffix = new char[word.size()+1];
		word.copy(T->u.suffix, word.size());
		cout<<"inserted : "<<T->u.suffix<<endl;
		return ; 
	}
	else {
		tptr parent = getTNode();
		char *old = T->u.suffix;
		// cout<<"old : "<<T->u.suffix<<endl;
		int charIndex = old[0];
		T->u.suffix = old + 1;
		// cout<<"old : "<<T->u.suffix<<endl;
		parent->u.bptr[charIndex] = T;
		T = parent;
	}
}

void insert(tptr &root, string word){
	int charIndex = word[0];
	// cout<<word<<charIndex<<endl;
	if(root == NULL) {
		root = getTNode();
		appendNode(root->u.bptr[charIndex], word.substr(1));
		
	}
	else{

		if (root->u.bptr[charIndex])
		{
			if(root->u.bptr[charIndex]->tag == 0) {
				appendNode(root->u.bptr[charIndex], word);
				// cout<<"if() tag : "<<root->u.bptr[charIndex]->tag<<endl;
			}

			if(word.length()>0) word = word.substr(1);
			insert(root->u.bptr[charIndex], word);
			
		}
		else {
			// cout<<"else "<<endl;
			if(word.length()>0) word = word.substr(1);

			appendNode(root->u.bptr[charIndex], word);
		}
	}
}

void print(tptr &T, char path[], int k){
	if(T==NULL) return;
	else if(T->tag==0){
		for (int i = 0; i < k; ++i)
		{
			cout<<path[i];
		}
		if(T->u.suffix)
			cout<<T->u.suffix;
		cout<<" ";
		return ;
	}
	for(int i=0 ; i < MAX_CHAR; i++){
		if(T->u.bptr[i]) {
			if(i == 0) {
				//end of the string
				print(T->u.bptr[i], path, k);
			}
			else{
				path[k] = i;
				print(T->u.bptr[i], path, k+1);
			}
			
		}
	}		
}

int main(){
	tptr root = NULL;
	string str[20] = {"aab","abbbc","baa","bccaa","bc","bca","cabb"};
	int i=0;
	insert(root,"abc");
	insert(root,"abbb");	
	insert(root,"abb");	
	while(str[i]!="\0"){
		insert(root,str[i]);
		i++;
	}

	cout<<"print : "<<endl;
	char path[100];
	print(root, path, 0);
	return 0;
}

// aab abb abbb abbbc abc baa bc bca bccaa cabb