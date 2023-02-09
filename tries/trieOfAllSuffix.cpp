#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256

typedef struct Tnode{

	Tnode *children[MAX_CHAR];
	vector<int> index;
}*tptr;

tptr getNewNode() {

	tptr newNode = new Tnode;
	for (int i = 0; i < MAX_CHAR; ++i)
	{
		newNode->children[i] = NULL;
	}

	return newNode;
}


void insert(tptr root, string pat, int index) {

	/**
	 *  pushing index into vector at each node ( max value is len+1)
	 */
	cout<<pat<<endl;
	root->index.push_back(index);

	if( pat.length() > 0) {

		int charIndex = pat[0];
		// cout<<pat[0]<<" - "<<charIndex<<endl;
		if(root->children[charIndex] == NULL) {
			root->children[charIndex] = getNewNode();
		}

		insert(root->children[charIndex], pat.substr(1), index+1);
	}
}

vector <int>* search(tptr root, string pat) {

	if(pat.length() == 0) {

		for (int i = 0; i < root->index.size(); ++i)
		{
			cout<<root->index[i]<<" ";
		}
		cout<<endl;
		return &(root->index);
	}
	int charIndex = pat[0];
	// cout<<pat[0]<<" - "<<charIndex<<endl;
	if(root->children[charIndex] != NULL) {
		return search(root->children[charIndex], pat.substr(1));
	}
	else {
		return NULL;
	}
}


void findPattern(tptr root, string pat) {

	vector <int> *list = search(root, pat);

	for (int i : *list) {
		cout<<i-pat.length()<<" ";
	}
		/* code */
	cout<<endl;
}

int main() {

	tptr root = getNewNode();

	string txt = "geeksforgeeks.org";

	// string txt = "banana";

	// cout<<txt.length();

	int i=0, n = txt.length();

	// cout<<txt.substr(1);

	while(i < n){
		insert(root, txt.substr(i), i);
		i++;
	}
	cout<<"findPattern -- \n";
	// findPattern(root,"ana");
	findPattern(root,"geeks");
	return 0;
}