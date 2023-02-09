#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


void print(std::vector< vector<int> > maze, int N){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

int isSafe( std::vector< vector<int> > soln, int N, int row, int col){
	for (int i = 0; i < col; ++i)
	{
		if (soln[row][i] == 1)
		{
			return false;
		}
	}
	for (int i = row-1, j = col-1; i>=0 && j>=0 ; i--, j--)
	{
		if (soln[i][j] == 1)
		{
			return false;
		}
	}
	for (int i = row+1, j = col-1; i < N && j>=0; ++i, j--)
	{
		if (soln[i][j] == 1)
		{
			return false;
		}
	}
	return true;
}

int solveNQutil(int col, std::vector< vector<int> > &soln, int N){


	if (col >= N) {
		return 1;
	}
	// back track for all possible next moves

	for (int row = 0; row < N; ++row)
	{

		if(isSafe(soln, N, row, col)){

			soln[row][col] = 1;

			if (solveNQutil(col+1, soln, N))
			{
				return 1;
			}
			else
				soln[row][col] = 0;
		}

	}
	return 0;
}
void solveKT(int N){

	std::vector< vector<int> > soln(N , std::vector<int> (N, 0));

	if(solveNQutil(0, soln, N)){
		cout<<"it is possible!!"<<endl;
	}
	cout<<"\n\nsolution matrix\n";
	print(soln,N);
}

int main(int argc, char const *argv[])
{

	int n =5;  // Higher values high TC
	solveKT(n);
	
	return 0;
}