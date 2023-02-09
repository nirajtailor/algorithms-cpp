#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


void print(std::vector< vector<int> > board, int N){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

int isSafe( std::vector< vector<int> > board, int N, int x, int y){
	return (x >=0 && x < N && y>=0 && y<N && board[x][y] == -1);
}
int solveKTutil(int x, int y, int move, std::vector< vector<int> > &board, int N, std::vector<pair<int, int > > xy){
	if (move == N*N) {
		cout<<"\n\n";
		print(board,N);
		return 1;
	}
	// back track for all possible next moves
	cout<<"move"<<move<<endl;
	for (int i = 0; i < 8; ++i)
	{
		int next_x = x + xy[i].first;
		int next_y = y + xy[i].second;

		if(isSafe(board, N, next_x, next_y)){
			board[next_x][next_y] = move;
			if (solveKTutil(next_x, next_y, move+1, board, N, xy))
			{
				return 1;
			}
			else
				board[next_x][next_y] = -1;
		}

	}
	return 0;
}
void solveKT(int N){

	std::vector< vector<int> > board(N, std::vector<int> (N,-1));
	print(board, N);
	int x[] = {2, 1, -1, -2, -2, -1, 1, 2};
	int y[] = {1, 2, 2, 1, -1, -2, -2, -1};
	std::vector<pair < int, int > > xy;
	for (int i = 0; i < 8; ++i)
	{
		xy.push_back(make_pair(x[i] , y[i]));
	}

	board[0][0] = 0;

	cout<<solveKTutil(0, 0, 1, board, N, xy);
	cout<<"\n\n";
	print(board,N);
}

int main(int argc, char const *argv[])
{

	int n =5;  // Higher values high TC
	solveKT(n);
	
	return 0;
}