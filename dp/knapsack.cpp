#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int recKnapsack(int value[], int weight[], int W, int n){

	if(W==0 || n == 0){
		return 0;
	}

	if(weight[n-1] > W){
		return recKnapsack(value, weight, W, n-1);	// not included
	}
	else{ // max ( included , not included)
		return max(value[n-1] + recKnapsack(value, weight, W-weight[n-1] ,n-1) , recKnapsack(value,weight,W,n-1));
	}
}

int dpKnapsack(int value[], int weight[], int W, int n){
	int weightMatrix[n+1][W+1];

	vector < pair < int , int> > vw;
	for (int i = 0; i < n; ++i)
	{
		vw.push_back(make_pair(weight[i], value[i]));
	}

	sort(vw.begin(), vw.end());


	for (int i = 0; i < n+1; ++i)
	{
		
		for (int j = 0; j < W+1; ++j)
		{
			if( i ==0 || j == 0) {
				weightMatrix[i][j] = 0;
			}
			else if(vw[i-1].first > j){

				weightMatrix[i][j]  = weightMatrix[i-1][j];
			}
			else{
				weightMatrix[i][j] = max(weightMatrix[i-1][j] , vw[i-1].second + weightMatrix[i-1][j-vw[i-1].first]);
			}
		}
		/* code */
	}
	cout<<weightMatrix[n][W]<<endl;
	return weightMatrix[n][W];
}

bool compare(pair < int , int > a , pair < int , int > b){

	double r1 = a.second / a.first;
	double r2 = b.second / b.first;

	return r1>r2;	
}

int greadyKnapSack(int value[], int weight[], int W, int n){

	vector < pair < int , int> > vw;
	for (int i = 0; i < n; ++i)
	{
		vw.push_back(make_pair(weight[i], value[i]));
	}

	sort(vw.begin(), vw.end() , compare);

	int i =0 ;
	double totalVal = 0.0, currentweight = 0.0;

	while(i<n){
		if(vw[i].first + currentweight <= W){
			totalVal+=vw[i].second;
			currentweight+=vw[i].first;
		}
		else{
			double partialWeight = W - currentweight;
			double fraction = partialWeight/vw[i].first;
			cout<<"fraction "<<fraction<<endl;
			double partialValue = fraction*vw[i].second;
			totalVal+=partialValue;
			break;
		}
		i++;
	}
	return totalVal;

}

int main(){

	int value[] = {60,100,120};
	int weight[] = {10,20,30};

	// int value[] = {10,15,40};
	// int weight[] = {1,2,3};

	int W = 50;

	int result, result1, result2;
	int n;
	n = sizeof(value)/sizeof(value[0]);
	result = recKnapsack(value,weight,W, n );
	cout<<result<<endl;

	result1 = dpKnapsack(value,weight,W,n);

	cout<<result1<<endl;

	result2 = greadyKnapSack(value,weight,W,n);
	cout<<result2<<endl;

	return 0;
}