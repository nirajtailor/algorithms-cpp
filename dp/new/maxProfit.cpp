// Find the maximum profit using a given price array, only one buy and sell allow

// [6,3,4,8,5,4,2] profit = 5, buy 3 , sell 8

// [0,0,1,5]
// [-1,-1,1,1]

#include<iostream>

using namespace std;



void maxProfit(int arr[], int n){
	
	int max[2][n];

	for(int i=1; i<n; i++){

		max[0][i] = 0;
		max[1][i] = -1;

		for(int j=i-1; j>=0; j--){

			if(arr[j] < arr[i] && (arr[i] - arr[j]) > max[0][i]){

				max[0][i] = arr[i] - arr[j];
				max[1][i] = j;
			}
		}
	}
	int maxProfit = 0;
	int buy = -1, sell = -1;
	for(int i=1; i<n; i++){
		if(max[0][i]> maxProfit){
			maxProfit = max[0][i];
			sell = i;
			buy = max[1][i];
		}
	}

	if(buy != -1 && sell != -1){
		// print(maxProfit, arr[buy], arr[sell]);
		//maxProfit : 5, buy: 3, sell : 

		cout<<"maxProfit : "<<maxProfit<<arr[buy]<<arr[sell]<<endl;
	}
	else{
		// 
		cout<<"doesn't exist";
	}
	
}

int main(){

	// int arr[] = {6,3,4,8,5,4,2};

	int arr[] = {8,5,4,2};

	maxProfit(arr, sizeof(arr)/sizeof(arr[0]));
}


// {()}[), {(}) are not balanced or not

// {()}

