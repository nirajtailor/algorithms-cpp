#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int coinChange(int s[], int m, int totalSum, int x){

	if (x == 0 && totalSum==0)
	{
		return 1;
	}
	if (totalSum <= 0)
	{
		return 0;
	}
	if (m<=0 && totalSum>0)
	{
		return 0;
	}

	return coinChange(s, m-1 , totalSum, x) + coinChange(s, m, totalSum-s[m-1], x-1);
}

int coinChangeDP(int s[] , int m, int N, int x){
	int table[x+1][N+1][m];

	for (int i = 0; i < N+1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i==0)
			{
				table[0][i][j] = 1;
			}
			else{
				table[0][i][j] = 0;
			}
			
		}
	}
	

	for (int q = 1; q < x+1; ++q)
	{
		/* code */
		for (int i = 1; i < N+1 ; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int x = (i-s[j] >= 0) ? table[q-1][i-s[j]][j] : 0;
				int y = (j>0) ? table[q][i][j-1] : 0;

				table[q][i][j] = x + y;
			}
		}
	}
	
	return table[x][N][m-1];
}

int main(){
	cout<<"Correct ans : 5 \nwrong ans : 2 \nun attended : 3 :: \n";

	int totalSum = 24;
	int x = 6;
	int s[] = {2,5,3};
	int m;

// 12 = [5,2,2,3]
// 12 = [3,3,3,3]
	m = sizeof(s)/sizeof(s[0]);
	int res = coinChange(s,m,totalSum,x);
	int res1 = coinChangeDP(s,m,totalSum, x);
	cout<<res<<endl;
	cout<<res1<<endl;
	return 0;
}