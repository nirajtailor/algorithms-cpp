#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// A surpasser of an element of an array is a greater element to its right, 

void merge(int arr[], int l, int m, int r, unordered_map < int , int > &hash){
	int *temp = new int[r-l + 1];
	int i=l, j=m+1, k =0;
	while(i <= m && j <= r ){
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else {
			hash[arr[j]] += (m + 1 - i) ;
			temp[k++] = arr[j++];

		}
	}
	while(i <= m){
		temp[k++] = arr[i++];
	}
	while(j <= r){
		temp[k++] = arr[j++];
	}

	for (i = l, k = 0; k < r -l + 1; k++){\
		cout<<temp[k]<<" ";
		arr[i++] = temp[k];
	}
	cout<<endl;
}

void mergeDesc(int arr[], int l, int m, int r, unordered_map < int , int > &hash){
	int *temp = new int[r-l + 1];
	int i=l, j=m+1, k =0;
	int c = 0;

	while(i <= m && j <= r ){
		if(arr[i] > arr[j]){
			hash[arr[i]] += c;
			temp[k++] = arr[i++];
		}
		else {
			c++;
			temp[k++] = arr[j++];
		}
	}

	while(i <= m){
		hash[arr[i]] += c;
		temp[k++] = arr[i++];
	}
	while(j <= r){
		temp[k++] = arr[j++];
	}

	for (i = l, k = 0; k < r -l + 1; k++){\
		// cout<<temp[k]<<" : "<<hash[temp[k]]<<endl;
		arr[i++] = temp[k];
	}
	//cout<<endl;
}

void mergeSort(int arr[], int l, int r, unordered_map < int , int > &hash){
	if(r>l){
		int mid = l + (r-l)/2;
		mergeSort(arr, l, mid , hash);
		mergeSort(arr, mid + 1, r, hash);

		// cout<<arr[l]<<" <-> "<<arr[mid+1]<<" <-> "<<arr[r]<<endl;

		// merge(arr, l, mid, r, hash);
		mergeDesc(arr, l, mid, r, hash);
	}
}

void mergeUtil(int arr[], int n){
	int *temp = new int[n];

	unordered_map < int , int > hash;
	mergeSort(arr, 0, n-1 , hash);
	cout<<"sorted - > \n";
	for (int k = 0; k < n; k++){
		cout<<arr[k]<<" "<<hash[arr[k]]<<endl;
	}
}


int main(int argc, char const *argv[])
{
	int arr[] = {31,35,73,32,7,46,86,12,16,25};
	// int arr[] = {8,4,2,1};
	// int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int k = 0; k < n; k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	mergeUtil(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}