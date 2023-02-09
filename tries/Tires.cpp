#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int n = 26;

union pointer{
	struct Tnode *Bptr[n];
	char *str;
};

typedef struct Tnode{
	int tag;
	union pointer u;
}*Tptr;

void newnode(Tptr &T, string word, int k){
	if(T==NULL){
		T = new Tnode;
		T->tag = 0;
		T->u.str = new char[word.size()+1];
		word.copy(T->u.str, word.size());
		return ;
	}
	else{
		Tptr p = new Tnode;
		p->tag = 1;
		for(int i=0 ; i<n; i++) 
			p->u.Bptr[i] = NULL;

		char *old = T->u.str;
		int j = old[k+1] - 'a' + 1;
		if (j<0) j = 0;

		p->u.Bptr[j] = T ;
		T = p;
	}
}

void insert(Tptr &T, string word, int k){
	if (T == NULL){
		T = new Tnode;
		T->tag = 1;
		for(int i=0 ; i<n; i++) 
			T->u.Bptr[i] = NULL;
		int j = word[k]-'a' + 1;
		newnode(T->u.Bptr[j], word , k);
	}
	else{
		int j = word[k]-'a' + 1;
		if (j<0) j = 0;

		if(T->u.Bptr[j]){
			if(T->u.Bptr[j]->tag == 0){
				newnode(T->u.Bptr[j],word, k);
			}
			insert(T->u.Bptr[j], word , k+1);
		}
		else{
			newnode(T->u.Bptr[j],word,k);
		}

	}
}

void print(Tptr &T){
	if(T==NULL) return;
	else if(T->tag==0){
		cout<<T->u.str<<" ";
		return ;
	}
	for(int i=0 ; i < n; i++)
		print(T->u.Bptr[i]);
}

int main(){
	Tptr root = NULL;

	string str[20] = {"aab","abbbc","baa","bccaa","bc","bca","cabb"};
	int i=0;
	insert(root,"abc",0);
	insert(root,"abbb",0);	
	insert(root,"abb",0);	
	cout<<"\n";
	while(str[i]!="\0"){
	insert(root,str[i],0);
	i++;
	}
	print(root);
	return 0;
}