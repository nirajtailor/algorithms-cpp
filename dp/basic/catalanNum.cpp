#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

/*
The Number of correct bracket sequence consisting of n opening and n closing brackets.

The number of rooted full binary trees with n+1 leaves (vertices are not numbered).
A rooted binary tree is full if every vertex has either two children or no children.

The number of ways to completely parenthesize n+1 factors.

The number of triangulations of a convex polygon with n+2 sides (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).

The number of ways to connect the 2n points on a circle to form n disjoint chords.

The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).

The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n×n, 
which do not pass above the main diagonal (i.e. connecting (0,0) to (n,n)).

Number of permutations of length n that can be stack sorted 
(i.e. it can be shown that the rearrangement is stack sorted if and only if there is no such index i<j<k, such that ak<ai<aj ).

The number of non-crossing partitions of a set of n elements.

The number of ways to cover the ladder 1…n using n rectangles 
(The ladder consists of n columns, where ith column has a height i).

*/

void CatalanNumber(int n){

	unsigned long int cat[n+1];
	cat[0] = cat[1] = 1;
	cout<<cat[0]<<" , "<<cat[1];
	for (int i = 2; i <= n; ++i)
	{
		cat[i] = 0;
		for (int j = 0; j < i; ++j)
		{
			cat[i] += cat[j]*cat[i-j-1];
		}
		cout<<" , "<<cat[i];
	}
	cout<<endl;
}

int recCatalan(unsigned long int n){
	if (n <= 1)
	{
		return 1;
	}
	unsigned long int res = 0;

	for (int i = 0; i < n; ++i)
	{
		res += recCatalan(i)*recCatalan(n-i-1);
	}

	return res;
}

int main(){

	int n = 5;
	CatalanNumber(n);

	cout<<"recCatalan : "<<recCatalan(n)<<endl;
	return 0;
}