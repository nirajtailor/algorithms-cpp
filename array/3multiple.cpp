#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

// void extract(int rem, priority_queue<int>)
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

	queue <int > q;
	q.push(10);
	
	cout<<q.front()<<endl;

	// priority_queue<int> Q0,Q1,Q2;

	priority_queue <int, vector<int>, greater<int> > Q0,Q1,Q2;

	int arr[] = {5,5,5,7};
	int n, sum=0;
	n = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i];
		if(arr[i]%3 == 0)
			Q0.push(arr[i]);
		else if(arr[i]%3 == 1)
			Q1.push(arr[i]);
		else
			Q2.push(arr[i]);
	}
	// cout<<Q0.top()<<endl;
	// cout<<Q1.top()<<endl;
	// cout<<Q2.top()<<endl;
	cout<<sum<<endl;

	if(sum%3==1){
		if(Q1.size()>0)	Q1.pop();
		else if(Q2.size() > 1){
			Q2.pop();Q2.pop();
		}
		else{
			cout<<"not possible"<<endl;
		}
	}
	else if( sum%3 == 2){
		if(Q2.size()>0)	Q2.pop();
		else if(Q1.size() > 1){
			Q1.pop();Q1.pop();
		}
		else{
			cout<<"not possible"<<endl;
		}
	}
	
	cout<<Q0.size()<<Q1.size()<<Q2.size()<<endl;

	while(Q1.size())
	{
		Q0.push(Q1.top());
		Q1.pop();
	}
	while(Q2.size())
	{
		Q0.push(Q2.top());
		Q2.pop();
	}

	cout<<Q0.size()<<Q1.size()<<Q2.size()<<endl;

	// cout<<Q1.top()<<Q2.top()<<endl;

	while(Q0.size())
	{
		cout<<Q0.top();
		Q0.pop();
	}
	cout<<endl;
}
