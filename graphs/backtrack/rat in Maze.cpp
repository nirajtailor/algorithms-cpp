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

int isSafe( std::vector< vector<int> > maze, int N, int x, int y){
	return (x >=0 && x < N && y>=0 && y<N && maze[x][y] == 1);
}
int solveKTutil(int x, int y, std::vector< vector<int> > &maze, int N, 
				std::vector<pair<int, int > > xy, std::vector< vector<int> > &soln){


	if (x == N-1 && y == N-1 && maze[x][y]==1) {
		return 1;
	}
	// back track for all possible next moves

	for (int i = 0; i < 2; ++i)
	{
		int next_x = x + xy[i].first;
		int next_y = y + xy[i].second;

		if(isSafe(maze, N, next_x, next_y)){

			if (soln[next_x][next_y] == 1)
				return 0;

			soln[next_x][next_y] = 1;
			if (solveKTutil(next_x, next_y, maze, N, xy, soln))
			{
				return 1;
			}
			else
				soln[next_x][next_y] = 0;
		}

	}
	return 0;
}
void solveKT(int N){

	std::vector< vector<int> > maze{
		{1, 0, 0, 0 , 1},
		{1, 1, 0, 1, 1},
		{0, 1, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
	};
	std::vector< vector<int> > soln(N , std::vector<int> (N, 0));

	int x[] = {1, 0};
	int y[] = {0, 1};

	std::vector<pair < int, int > > xy;
	for (int i = 0; i < 2; ++i)
	{
		xy.push_back(make_pair(x[i] , y[i]));
	}
	if(solveKTutil(0, 0, maze, N, xy, soln)){
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