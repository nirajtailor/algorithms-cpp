#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find_pivot(int arr[], int l, int h){

	if(l>h)
		return -1;
	if(arr[l] <= arr[h])
		return l;

	int m = l + (h-l)/2;

	// excluding i which is m<i<=h
	if (arr[m] < arr[h]){
		return find_pivot(arr, l, m);
	}
		// exclude l<=i<=m 
	return find_pivot(arr, m+1, h);
}

int binary_search(int arr[], int l, int h, int key){
	if(l>h)
		return -1;

	int m = l + (h-l)/2;

	if (arr[m] == key)
		return m;
	if(arr[m] < key)
		return binary_search(arr, m+1, h, key);

	return binary_search(arr, l, m-1, key);
}

// int lower_bound(int arr[] , int l, int h, int key){
// 	if(l>h) reteurn -1;

// 	int m = l + (h-l)/2;

// 	if(arr[m] == key){
// 		if(l<m && arr[m])
// 	}

// }

int search_rotated(int arr[], int l, int h, int key){

	int pivot_index = find_pivot(arr, l,h);

	if(key == arr[pivot_index])
		return pivot_index;
	if(key < arr[h])
		return binary_search(arr, pivot_index+1, h, key);
	cout<<"pivot_index = "<<pivot_index<<endl;
	return binary_search(arr, l, pivot_index-1, key);
}

// its call by reference
int doublearr(int a[], int n){
	for(int i=0; i<=n; i++){
		a[i]*=4;
	}
}

int main(){

	int arr[] = {4,5,6,7,8,9,1};
	cout<<find_pivot(arr, 0, sizeof(arr)/sizeof(arr[0])-1)<<endl;

	int key = 10;
	int arr1[] = {4,5,6,7,8,9,10};
	cout<<binary_search(arr1, 0, sizeof(arr1)/sizeof(arr1[0])-1, key)<<endl;

	int arr2[] = {4,5,6,7,8,9,10,1,2,3};
	cout<<search_rotated(arr2, 0, sizeof(arr2)/sizeof(arr2[0])-1, key)<<endl;

	doublearr(arr, sizeof(arr)/sizeof(arr[0])-1);

	for(int i=0; i < sizeof(arr)/sizeof(arr[0]); i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}