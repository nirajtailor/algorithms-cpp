#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){ return (a>b) ? a : b;}

int cuttingrodRec(int price[], int n){

	if (n<=0)
	{
		return 0;
	}
	int max_val = 0;
	for (int i = 0; i < n; ++i)
	{
		max_val = max(max_val , price[i] + cuttingrodRec(price, n-i-1));
	}

	return max_val;
}

int cuttingrodDP(int price[] , int n){

	int cost[n+1][n+1];

	for (int i = 0; i < n+1; ++i)
	{
		/* code */
		cost[i][0] = 0;
		cost[0][i] = 0;
	}

	for (int i = 1; i < n+1; ++i)
	{
		/* code rod len = j*/
		for (int j = 1; j < n+1; ++j)
		{
			/* code */
			if (i <= j)
			{
				/* code */
				cost[i][j] = max(cost[i-1][j], price[i-1] + cost[i][j-i]);
			}
			else
				cost[i][j] = cost[i-1][j];
		}

	}
	return cost[n][n];
}

int main(){
	int arr[] = {1,5,8,9,10,17,17,20};
	int n = sizeof(arr)/sizeof(arr[0]);

	int max_value = cuttingrodRec(arr,n);


	cout<<"max_value : "<<max_value<<endl;

	max_value = cuttingrodDP(arr, n);

	cout<<"max_value DP : "<<max_value<<endl;
}