#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int coinChange(int s[], int m, int N){

	if (N==0)
	{
		return 1;
	}
	if (N<0)
	{
		return 0;
	}
	if (m<=0 && N>0)
	{
		return 0;
	}

	return coinChange(s, m-1 , N) + coinChange(s, m, N-s[m-1]);
}

int coinChangeDP(int s[] , int m, int N){
	int table[N+1][m];

	for (int i = 0; i < m; ++i)
	{
		table[0][i] = 1;
	}

	for (int i = 1; i < N+1 ; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x = (i-s[j] >= 0) ? table[i-s[j]][j] : 0;
			int y = (j>0) ? table[i][j-1] : 0;

			table[i][j] = x + y;
		}
	}
	return table[N][m-1];
}

int main(){
	cout<<"coin change problem :: ";
	int N = 10;

	int s[] = {2,5,3,6};
	int m;

	m = sizeof(s)/sizeof(s[0]);
	int res = coinChange(s,m,N);
	int res1 = coinChangeDP(s,m,N);
	cout<<res<<endl;
	cout<<res1<<endl;
	return 0;
}