#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
	if (a>b){
		return a;
	}
	return b;
}
int maximum_sum(int arr[], int n, bool flag){
	if (n==1)
	{
		if (flag)
		{
			return arr[0];
		}
		else{
			return 0;
		}
	}

	if (flag){
		return arr[n-1] + maximum_sum(arr, n-1, false);
	}
	else
		return max(maximum_sum(arr, n-1, true) , maximum_sum(arr, n-1, false));

}

void maximum_sum_util(int arr[], int n){
	int exc, inc;
	exc = maximum_sum(arr, n, 0);
	inc = maximum_sum(arr, n, 1);

	cout<<" \nexc : "<<exc<<endl;
	cout<<" \ninc : "<<inc<<endl;

	cout<<max(exc, inc)<<endl;
}

int main(){

	int arr[] = {5,5,10,100,10,5};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n;
	maximum_sum_util(arr, n);
	return 0;
}