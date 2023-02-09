// longest palindromic subsequence  - rec and dp
// count all palindromic subsequences - rec and dp
// longest palindromic substring  - dp
// count all palindromic substrings -  dp

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int max( int a, int b){
	if (a>b)
	{
		return a;
	}
	else
		return b;
}

int LPSubsequence(string str, int i, int j){

	if(i==j){
		return 1;
	}
	else if(i+1 == j && str[i] == str[j]){
		return 2;
	}
	if (str[i] == str[j])
	{
		return 2 + LPSubsequence(str, i+1 , j-1);
	}
	else{
		return max(LPSubsequence(str, i+1, j), LPSubsequence(str, i, j-1));
	}

}

int LPSubsequenceDP(string str){
	int n = str.length();

// initialize with zero 2d vector
	vector < vector< int >> dp(n, vector<int> (n, 0));

	cout<<dp[0][0]<<endl;

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
	}

	for (int k = 2; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1; ++i)
		{
			int j = i + k-1;

			if(i+1 == j && str[i] == str[j]){
				dp[i][j] = 2;
			}

			else if (str[i] == str[j])
			{
				dp[i][j] = 2 + dp[i+1][j-1];
			}
			else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	return dp[0][n-1];
}

int countPS(string str, int i, int j){
	if(i==j){
		return 1;
	}
	else if (j<i)
	{
		return 0;
	}
	else if (str[i] == str[j])
	{
		return countPS(str, i+1, j) + countPS(str, i, j-1) + 1;
		// countPS(str, i+1, j-1)- countPS(str, i+1, j-1)
	}
	else{

		return countPS(str, i+1, j) + countPS(str, i, j-1) - countPS(str, i+1, j-1);
	}
}

int countPSDP(string str){
	int n = str.length();

// initialize with zero 2d vector
	vector < vector< int >> dp(n, vector<int> (n, 0));

	cout<<dp[0][0]<<endl;

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
	}

	for (int k = 2; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1; ++i)
		{
			int j = i + k-1;

			if (str[i] == str[j])
			{
				dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
			}
			else{
				dp[i][j] = dp[i+1][j] +  dp[i][j-1] -  dp[i+1][j-1];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	return dp[0][n-1];
}


int LPSubstringDP(string str){
	int n = str.length();

// initialize with zero 2d vector
	vector < vector< bool >> dp(n, vector<bool> (n, false));

	cout<<dp[0][0]<<endl;

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = true;
	}

	int max_length = 1;
	int start = 0;

	for (int k = 2; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1; ++i)
		{
			int j = i + k-1;

			if(i+1 == j && str[i] == str[j]){
				dp[i][j] = true;
				max_length = 2;
				start = i;
			}

			else if (dp[i+1][j-1] && str[i] == str[j])
			{
				dp[i][j] = true;
				if (k>max_length)
				{
					start = i;
					max_length = k;
				}
				
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	return max_length;
}

int countLPSubstringDP(string str){
	int n = str.length();

// initialize with zero 2d vector
	vector < vector< bool >> dp(n, vector<bool> (n, false));
	vector < vector< int >> count(n, vector<int> (n, 0));

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = true;
	}

	// k is the length of substring
	for (int k = 2; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1; ++i)
		{
			int j = i + k-1;

			if(i+1 == j && str[i] == str[j]){
				dp[i][j] = true;
				count[i][j] = 1;
			}

			else if (dp[i+1][j-1] && str[i] == str[j])
			{
				dp[i][j] = true;
				
			}

			if (dp[i][j])
			{
				count[i][j] = 1 + count[i][j-1] + count[i+1][j] - count[i+1][j-1];
			}
			else{
				count[i][j] = count[i][j-1] + count[i+1][j] - count[i+1][j-1];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<count[i][j]<<" ";
		}
		cout<<endl;
	}


	return count[0][n-1];
}

int main(){

	string str = "aaaa";

	int res1 = LPSubsequence(str, 0, str.length()-1);

	cout<<"res1 "<<res1<<endl;

	int res2 = countPS(str, 0, str.length()-1);

	cout<<" "<<res2<<endl;

	int res3 = LPSubsequenceDP(str);
	cout<<" "<<res3<<endl;
	int res4 = countPSDP(str);
	cout<<" "<<res4<<endl;


	int res5 = LPSubstringDP("geeksskeegg");
	cout<<" "<<res5<<endl;

	int res6 = countLPSubstringDP("abbaeae");
	cout<<" "<<res6<<endl;

	return 0;
}