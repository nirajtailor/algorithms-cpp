// trie 2 nd way

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int n = 26;

typedef struct Tnode{
	struct Tnode *child[n];
	bool isEnd;
}*Tptr;


Tptr  getNode(){
	Tptr T = new Tnode;
		T->isEnd = false;
		for( int i=0; i<n; i++){
			T->child[i] = NULL;
		}
}
void insertItr(Tptr &T, string word){
	if(T==NULL){
		T = getNode();
	}
	Tptr temp = T;
	for( int i=0; i<word.length() ; i++){
		int j = word[i] - 'a' + 1;
		if(temp->child[j] == NULL){
			temp->child[j] = getNode();
		}
		temp = temp->child[j];
	}
	temp->isEnd = true;
}

void insert(Tptr &T, string word) {

	if (T == NULL)
	{
		T = getNode();
	} 
	if(word.length() > 0) {
		int charIndex = word[0] - 'a' + 1;

		if (T->child[charIndex] == NULL)
		{
			T->child[charIndex] = getNode();
		}

		insert(T->child[charIndex], word.substr(1));
	}
	else {
		T->isEnd = true;
	}

}

bool search1(Tptr &T , string word){
	Tptr temp = T;
	for( int i=0; i<word.length() ; i++){
		int j = word[i] - 'a' + 1;
		if(temp->child[j] == NULL){
			return false;
		}
		
		temp = temp->child[j];
	}
	return (temp && temp->isEnd );
}

bool search(Tptr &T , string word){
	
	if(T == NULL) {
		return false;
	}
	if(word.length() == 0) {
		return (T && T->isEnd );
	}
	else{
		int charIndex = word[0] - 'a' + 1;

		if (T->child[charIndex] == NULL)
		{
			return false;
		}
		else{
			return search(T->child[charIndex], word.substr(1));
		}
	}
}

void print(Tptr T, char *word, int k){
	if(T==NULL) return ;
	if(T->isEnd){
		// cout<<"k="<<k;
		for(int i=0 ; i<k ; i++)
			cout<<word[i];
		cout<<" ";
	}
	for(int i = 1; i<n; i++){
		if(T->child[i]){
			word[k] = 'a' + i - 1 ;
			// cout<<word[k];
			// k++;
			print(T->child[i], word , k+1);
			// k--;
		}
	}
}

int main(){
	Tptr root = NULL;
	string str[20] = {"aab","abbbc","baa","bccaa","bc","bca","cabb"};
	int i=0;
	insert(root,"abc");
	insert(root,"abbb");	
	insert(root,"abb");	
	while(str[i]!="\0"){
		insert(root,str[i]);
		i++;
	}
	cout<<search(root, "abb")<<endl;
	cout<<search(root, "ccc")<<endl;
	cout<<search(root, "abc")<<endl;
	char word[30];
	int k = 0;
	cout<<"sorted order -> "<<endl;
	print(root, word, k);

	cout<<"\nThe End !!!\n";
	return 0;
}



// aab abb abbb abbbc abc baa bc bca bccaa cabb 

// aab abb abbb abbbc abc baa bc bca bccaa cabb 
