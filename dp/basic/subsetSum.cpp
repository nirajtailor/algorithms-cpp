#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

bool isSubset(int set[], int n, int targetSum){

	if (targetSum == 0)
	{
		return true;
	}
	if (n == 0)
	{
		return false;
	}

	if (set[n-1] > targetSum)
	{
		return isSubset(set, n-1, targetSum);
	}

	return isSubset(set, n-1, targetSum) || isSubset(set, n-1, targetSum - set[n-1]);
}

void printrec(int set[], int n, int targetSum, bool subset[][100], vector<int> &p){

	if (n == 0 && targetSum != 0)
	{
		return;
	}
	if (n == 0 && targetSum == 0)
	{
		
		for (int i = 0; i < p.size(); ++i)
		{
			cout<<p[i]<<" , ";
		}
		cout<<"!!\n";
		return;
	}

	if (subset[n-1][targetSum])
	{
		/* ignore current value set[n-1] */
		// create new array
		vector<int> b = p;
		printrec(set, n-1, targetSum, subset, b);
	}

	if (targetSum >= set[n-1] && subset[n-1][targetSum-set[n-1]])
	{
		/* include current value set[n-1] */
		p.push_back(set[n-1]);
		printrec(set, n-1, targetSum-set[n-1], subset, p);
	}

}

bool isSubsetDP(int set[], int n, int targetSum){

	// bool subset[n+1][targetSum+1];
	bool subset[100][100];
	// if sum is zero
	for (int i = 0; i < n+1; ++i)
	{
		subset[i][0] = true;
	}
	// if sum is not zero and set is empty
	for (int i = 1; i < targetSum+1; ++i)
	{
		subset[0][i] = false;
	}

// size = i, sum = j
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 0; j < targetSum+1; ++j)
		{
			if (j < set[i-1])
			{
				subset[i][j] = subset[i-1][j];
			}
			else{
				subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
			}
		}
	}
	if (subset[n][targetSum])
	{
		printMatix()
		vector<int> p;
		printrec(set, n, targetSum, subset, p);
	}
	return subset[n][targetSum];
}
int main(int argc, char const *argv[])
{
	int set[] = {3,34,4,12,5,2};
	int n = sizeof(set)/sizeof(set[0]);
	int targetSum = 7; 
	cout<<" ans :"<<isSubset(set, n, targetSum)<<endl;
	cout<<"\nprinting all possible subsets\n";
	if(isSubsetDP(set, n, targetSum)){
		cout<<"\nexist\n";
	}
	return 0;
}