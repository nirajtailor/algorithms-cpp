#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


bool cmp(int a, int b){
	if(a>b) return 1;
	else    return 0;
}

int* getint(){
	int * i = new int;
	*i = 4;
	cout<<*i<<endl;
	return i;
}
int main(){
	
	vector < int > v;
	vector < int >  :: iterator i;
	v.assign(5,10);
	i = v.begin();
	 i = v.insert(i+2,15);
	 cout<<*i<<endl;
	 i  = v.erase(i-1);
	 cout<<*i<<endl;
	for(i = v.begin() ; i != v.end() ; i++)
		cout<<*i<<" ";
		
	v.push_back(6);
	cout<<endl;
	sort(v.begin() ,v.end(), cmp) ;
	for(i = v.begin() ; i != v.end() ; i++)
		cout<<*i<<" ";

	char *a;
	int *b;
	cout<<"\nlen"<<sizeof(b);

	int *g = getint();
	cout<<g<<endl;
	cout<<"value"<<*g;
}
