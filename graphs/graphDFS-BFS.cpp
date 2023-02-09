#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


void print(vector < pair<int , int > >  v[], int V){
	for (int i = 0; i < V; ++i)
	{
		cout<<i<<" adj vetices";
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout<<"{ "<<v[i][j].first<<", "<<v[i][j].second<<" } ";
		}
		cout<<endl;
	}
}

void make_adjList(vector < pair<int , int > >  v[], int src, int dest, int weight){
	
	v[src].push_back(make_pair(dest,weight));
	v[dest].push_back(make_pair(src,weight));		// undirected graph
}

void DFSutils(int current, vector < pair<int , int > >  adjlist[], vector<bool> &visited,  vector<int> &path, int V, int l){
	if(!visited[current])
		cout<<current<<", ";

	visited[current] = true;
	path[l] = current;
	cout<<"l"<<l<<" "<<path[l]<<endl;

	// if(l==V-1){
	// 	for(int k=0; k<=l; k++)	cout<<path[k]<<" ";
	// 	cout<<endl;
	// 	return;
	// }

	for (int i = 0; i < adjlist[current].size(); ++i)
	{	int v = adjlist[current][i].first;
		if (!visited[v])
		{
			DFSutils(v,adjlist,visited, path, V, l+1);
		}
	}
}

void DFS(vector < pair<int , int > >  adjlist[], int V){

	vector<bool> visited(V, false);
	vector<int> path(V, -1);
	DFSutils(3, adjlist, visited, path, V, 0);
	for (int i = 0; i < path.size(); ++i)
	{
		cout<<path[i]<<" ";
	}
}


int main(){

	int V =  4;

	vector < pair<int , int > >  v[V];

	// make_adjList(v, 0, 1, 4);
	// make_adjList(v, 0, 7, 8);
	// make_adjList(v, 1, 2, 8);
	// make_adjList(v, 1, 7, 11);
	// make_adjList(v, 2, 3, 7);
	// make_adjList(v, 2, 8, 2);
	// make_adjList(v, 2, 5, 4);
	// make_adjList(v, 3, 4, 9);
	// make_adjList(v, 3, 5, 14);
	// make_adjList(v, 4, 5, 10);
	// make_adjList(v, 5, 6, 2);
	// make_adjList(v, 6, 7, 1);
	// make_adjList(v, 6, 8, 6);
	// make_adjList(v, 7, 8, 7);

	// g.addEdge(0, 1);
 //    g.addEdge(0, 2);
 //    g.addEdge(1, 2);
 //    g.addEdge(2, 0);
 //    g.addEdge(2, 3);
 //    g.addEdge(3, 3);

    make_adjList(v, 0, 1, 7);
    make_adjList(v, 0, 2, 7);
    make_adjList(v, 1, 2, 7);
    // make_adjList(v, 2, 0, 7);
    make_adjList(v, 2, 3, 7);
    make_adjList(v, 3, 3, 7);

	print(v,V);

	//DjShortestPath(v,V,0);

	//primsMST(v,V,0);

	DFS(v,V);
	return 0;
}