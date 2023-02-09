#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


int r_count(int arr[], int n, int K){
	if (K<1)
	{
		return 0;
	}
	if (n==1)
	{
		if (arr[0]<=K)
		{
			return 1;
		}
		else{
			return 0;
		}
	}
	if (arr[n-1] <= K)
	{
		return r_count(arr, n-1, K/arr[n-1]) + r_count(arr, n-1, K) + 1; // single element
	}
	else{
		return r_count(arr, n-1, K);
	}
}

int main(){

	// int arr[] = {1,2,3,4};
	int arr[] = {4,8,7,2};
	int K = 50;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n;
	int ans = r_count(arr, n, K);
	cout<<" ans : "<<ans<<endl;
}