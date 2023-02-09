#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int main(){
	set < int > s;
	s.insert(100);
	s.insert(50);
	s.insert(20);
	s.insert(30);
	s.insert(90);
	s.insert(50);
	
	for(auto &x : s) cout<<x<<" ";
	//for(auto &x : s) cout<<*x<<" ";	


	char a = 'a';
	cout<<a<<endl;
	int b = a;	
	cout<<b<<endl;

	string str = "abc";

	cout<<str.substr(2);

	char *name = new char[str.size() + 1];
	str.copy(name, str.size());
	cout<<name;
	// int k = name[2];
	// cout<<k<<endl;

	char *word = &str[0];
	cout<<word<<endl;

	char *word2 = word + 3;
	cout<<word2<<endl;
}
