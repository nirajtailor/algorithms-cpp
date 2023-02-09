#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct node {
	int min, max;
};


struct node getminmax(int arr[], int l, int h){
	struct node minmax, mml, mmr;
	int mid;

	if(l == h){
		minmax.min = arr[l];
		minmax.max = arr[l];
		return minmax;
	}

	if(h-l == 1){
		if(arr[l] < arr[h]){
			minmax.min = arr[l];
			minmax.max = arr[h];
		}
		else{
			minmax.min = arr[h];
			minmax.max = arr[l];
		}
		return minmax;
	}

	mid = l + (h-l)/2;
	mml = getminmax(arr, l, mid);
	mmr = getminmax(arr, mid+1, h);

	if(mml.min < mmr.min){
		minmax.min = mml.min;
	}
	else {
		minmax.min = mmr.min;
	}

	if(mml.max < mmr.max){
		minmax.max = mmr.max;
	}
	else{
		minmax.max = mml.max;
	}

	return minmax;
}


void swap(int &x, int &y){
	int temp = y; y = x; x = temp;
	y = x + y - (x = y );
	y = x^y^(x = y);
}


void heapify(int arr[], int i , int size){

	if(i >= size/2) return ;	 // leaf node or doesn't exist

	int left = 2*i + 1;
	int right = 2*i + 2;

	int smallest = arr[left] < arr[i] ? left : i;

	if(right < size){
		smallest = arr[right] < arr[smallest] ? right : smallest;
	}

	if(smallest != i){
		swap(arr[i], arr[smallest]);
		heapify(arr,smallest,size);
	}

}

void maxheapify(int arr[], int i , int size){

	if(i >= size/2) return ;

	int left = 2*i + 1;
	int right = 2*i + 2;

	int largest = arr[left] > arr[i] ? left : i;

	if(right < size){
		largest = arr[right] > arr[largest] ? right : largest;
	}

	if(largest != i){
		swap(arr[i], arr[largest]);
		maxheapify(arr,largest,size);
	}

}

// Heapify procedure can be applied to a node only if its children nodes are heapified.
// So the heapification must be performed in the bottom up order.
//A sorting algorithm is said to be stable if two objects with equal keys appear in the 
//same order in sorted output as they appear in the input array to be sorted.

// heap sort is not stable 
void heapsort(int arr[] , int n){

	cout <<"descending order sorting using min heap"<<endl;

	for (int i = n/2-1; i >=0; i--){  // 2nd last row of tree
		heapify(arr, i,n);	
	}
	// sorting 
	for(int i = n-1 ; i>= 0 ; i--){
		swap(arr[0],arr[i]);
		heapify(arr, 0,i);	// size gets reduce so that it can't tauch sorted nodes'];

	}
	for(int i=0; i < n; i++)
		cout<<arr[i]<<" ";


	cout <<"\nAscending order sorting using max heap"<<endl;


	for (int i = n/2-1; i >=0; i--){
		maxheapify(arr, i,n);	
	}
	// sorting
	for(int i = n-1 ; i>= 0 ; i--){
		swap(arr[0],arr[i]);
		maxheapify(arr, 0,i);
	}
	for(int i=0; i < n; i++)
		cout<<arr[i]<<" ";

}

int main(){

	int arr[] = {40,5,65,37,8,29,100,7,1};
	struct node minmax = getminmax(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	cout<<"minimun = "<<minmax.min<<endl;
	cout<<"maximum = "<<minmax.max;
	cout<<endl;

	int a=10, b = 20;

	swap(a,b);
	cout<<"swap(10,20)= "<<a<<" "<<b<<endl;

	cout<<"Time complexity of heapify is O(Logn)"<<endl;
	cout<<"Overall time complexity of Heap Sort is O(nLogn)"<<endl;

	heapsort(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}