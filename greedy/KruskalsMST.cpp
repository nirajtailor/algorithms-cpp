#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

// 1. Sort all the edges in non-decreasing order of their weight. 
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 
// 		If cycle is not formed, include this edge. Else, discard it. 
// 3. Repeat step#2 until there are (V-1) edges in the spanning tree.

// prism mst
// The Greedy Choice is to pick the smallest weight edge that connects the two sets.
// 1) Create a set mstSet that keeps track of vertices already included in MST. 
// 2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 
// 		for the first vertex so that it is picked first. 
// 3) While mstSet doesn’t include all vertices 
// 	a) Pick a vertex u which is not there in mstSet and has minimum key value. 
// 	b) Include u to mstSet. 
// 	c) Update key value of all adjacent vertices of u. To update the key values, iterate through all

typedef struct GraphNode {
	int src;
	int dest;
	int weight;
}*gptr;


typedef struct setnode{
	int V,E;
	gptr edge;
	int *parent;
}*mstptr;



void createGraph(gptr graph, int i, int src, int dest, int weight){

	graph[i].src = src;
	graph[i].dest = dest;
	graph[i].weight = weight;

}


bool compare(GraphNode a, GraphNode b){
	return a.weight < b.weight;
}

int find(int *parent, int v){

	if(parent[v] == -1)
		return v;
	find(parent, parent[v]);
}

void Union(int *parent, int x, int y){
	parent[x] = y;
}

void createMST(mstptr set){

	int i=0,v=0;
	int totalweight = 0;
	while(v < set->V-1 && i < set->E){
		int x = find(set->parent, set->edge[i].src);
		int y = find(set->parent, set->edge[i].dest);
		
		if(x!=y){
			Union(set->parent, x,y);
			totalweight+=set->edge[i].weight;
			cout<<"edge "<<set->edge[i].weight<<" added "<<endl;
			v++;
		}
		i++;
	}

	cout<<"minimum weight "<<totalweight<<endl;

}

int main(){
	mstptr set = new setnode;
	set->E = 5;
	set->V = 4;
	set->parent = new int[set->V];
	for (int i = 0; i < set->V; ++i)
	{
		set->parent[i] = -1;
	}
	set->edge = new GraphNode[set->E];

	createGraph(set->edge, 0, 0, 1, 10);
	createGraph(set->edge, 1, 0, 2, 6);
	createGraph(set->edge, 2, 0, 3, 5);
	createGraph(set->edge, 3, 1, 3, 15);
	createGraph(set->edge, 4, 2, 3, 4);

	sort(set->edge, set->edge+set->E, compare);

	cout<<set->edge[0].weight<<endl;

	createMST(set);

	return 0;
}

