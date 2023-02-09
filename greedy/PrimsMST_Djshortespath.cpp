#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
// struct Graph{


	
// };

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
	// undirected graph
	v[src].push_back(make_pair(dest,weight));
	v[dest].push_back(make_pair(src,weight));
}

void DjShortestPath(vector < pair<int , int > >  adjlist[], int V, int src){

	set< pair < int , int> >setDJ;
	vector<int> distance(V,INF);

	setDJ.insert(make_pair(0,src));
	distance[src] = 0;

	while(!setDJ.empty()){

		pair < int, int > temp = *(setDJ.begin());
		setDJ.erase(setDJ.begin()); // setDJ.erase(temp);
		cout<<"\nextracted "<<temp.first<<", "<<temp.second;

		int u = temp.second;
		// adjacent vertex
		for (int j = 0; j < adjlist[u].size(); ++j)
		{
			int v = adjlist[u][j].first;
			int w = adjlist[u][j].second;

			cout<<"{ "<<v<<", "<<w<<" } ";
			if (distance[v] > distance[u] + w)
			{
				if (distance[v]!=INF)
				{
					// if pair already exist with higher weight
					setDJ.erase(setDJ.find(make_pair(distance[v], v)));
				}
				distance[v] = distance[u] + w;
				setDJ.insert(make_pair(distance[v], v));
			}

		}
	}

	for (int i = 0; i < V; ++i)
	{
		cout<<"vertex "<<i<<" shortestPath "<<distance[i]<<endl;
	}
}

void primsMST(vector < pair<int , int > >  adjlist[], int V, int src){

	set< pair < int , int> >setMST;
	vector<int> key(V,INF);
	vector<bool> visited(V, false);

	setMST.insert(make_pair(0,src));
	key[src] = 0;

	while(!setMST.empty()){

		pair < int, int > temp = *(setMST.begin());
		setMST.erase(setMST.begin()); // setMST.erase(temp);
		cout<<"\nextracted "<<temp.first<<", "<<temp.second;

		int u = temp.second;
		visited[u] = true;
		// adjacent vertex
		for (int j = 0; j < adjlist[u].size(); ++j)
		{
			int v = adjlist[u][j].first;
			int w = adjlist[u][j].second;

			cout<<"{ "<<v<<", "<<w<<" } ";
			if (visited[v] == false && key[v] > w)
			{
				if (key[v]!=INF)
				{
					setMST.erase(setMST.find(make_pair(key[v], v)));
				}
				key[v] = w;
				setMST.insert(make_pair(w, v));
			}

		}
	}

	for (int i = 0; i < V; ++i)
	{
		cout<<"vertex "<<i<<" key "<<key[i]<<endl;
	}
}

int main(){

	int V =  9;

	vector < pair<int , int > >  v[V];

	make_adjList(v, 0, 1, 4);
	make_adjList(v, 0, 7, 8);
	make_adjList(v, 1, 2, 8);
	make_adjList(v, 1, 7, 11);
	make_adjList(v, 2, 3, 7);
	make_adjList(v, 2, 8, 2);
	make_adjList(v, 2, 5, 4);
	make_adjList(v, 3, 4, 9);
	make_adjList(v, 3, 5, 14);
	make_adjList(v, 4, 5, 10);
	make_adjList(v, 5, 6, 2);
	make_adjList(v, 6, 7, 1);
	make_adjList(v, 6, 8, 6);
	make_adjList(v, 7, 8, 7);

	print(v,V);

	DjShortestPath(v,V,0);

	primsMST(v,V,0);
	return 0;
}