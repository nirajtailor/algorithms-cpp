// Merge two Sorted Arrays Without Extra Space
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements. 

// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 3, arr2[] = [2 3 9]

// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]



// [1 2, 3, 4] 
// [8 9 10]

// Sort an array of 0s, 1s and 2s
// Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// [0,0,0]

// {
// 	nzeros,
// 	nones,
// 	ntwos
// }


// 	   i, 	 k
// 0 ,0, 1, 1, 2 ,2
// 	         j


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void util(int arr1[], int arr2[], int n, int m){
	
	int i=n-1;
	int j = m-1;

	while(j>=0){ //O(m)

		if(arr1[i] > arr2[j]){
			swap(arr1[i], arr2[j]);
			j--;

			sort(arr1 , arr1+n);	//O(n)
		}
		else{
			j--;
		}

	}

	for (int i = 0; i < n; ++i)
	{
		cout<<arr1[i]<<" ";
	}
	for (int i = 0; i < m; ++i)
	{
		cout<<arr2[i]<<" ";
	}

}

// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
int main(int argc, char const *argv[])
{
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {0, 2, 6, 8, 9};

	int n = 4, m = 5;

	util(arr1, arr2, n, m);

	return 0;
}


