/* Author: Deven Prajapati ( DP009 ) */

/* 
Problem Statement: 
You have been given a Tree consisting of N nodes. A tree is a fully-connected graph consisting of N nodes and  edges. 
The nodes in this tree are indexed from 1 to N. Consider node indexed 1 to be the root node of this tree. 
The root node lies at level one in the tree. 
You shall be given the tree and a single integer x . You need to find out the number of nodes lying on level x.
*/

#include <bits/stdc++.h>

using namespace std;

/* 
BFS function 

parameters to be passed: root, adjList, visited Array, level Array

read: root node, adjList of edges, 
update: visited array, level array
*/

void bfs(int root, vector<int> adjList[], bool *isNodeVisited, int *level) {
	queue<int> myQueue;

	myQueue.push(root);
	level[root] = 1;
	isNodeVisited[root] = true;

	while(!myQueue.empty()) {
		int parent = myQueue.front();

		myQueue.pop();

		for(int i=0;i<(int)adjList[parent].size();i++) {
			int child = adjList[parent][i];
			if(!isNodeVisited[child]) {
				myQueue.push(child);
				level[child] = level[parent] + 1;
				isNodeVisited[child] = true;
			}
		}
	}

	return;
}

int main() {
	int nodes,edges;
	cin>>nodes;
	edges = nodes-1;

	vector<int> adjList[nodes+1];

	for(int i=0;i<edges;i++) {
		int nodeA,nodeB;
		cin>>nodeA>>nodeB;
		adjList[nodeA].push_back(nodeB);
    	adjList[nodeB].push_back(nodeA);
	}

	bool isNodeVisited[nodes+1];
	for(int i=0;i<=nodes;i++) isNodeVisited[i] = false;

	int level[nodes+1];
	for(int i=0;i<=nodes;i++) level[i] = -1;

	bfs(1,adjList,isNodeVisited,level);

	int query;
	cin>>query;

	int count = 0;
	for(int i=1;i<=nodes;i++) if(level[i] == query) count++;

	cout<<count<<endl;
}
