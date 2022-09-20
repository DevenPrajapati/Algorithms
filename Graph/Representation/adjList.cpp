/* Author: Deven Prajapati ( DP009 ) */

/* 
Problem Statement: 
You have been given an undirected graph consisting of N nodes and M edges. This graph can consist of self-loops as well as multiple edges. 
In addition , you have also been given Q queries. For each query , you shall be given 2 integers A and B. 
You just need to find if there exists an edge between node A and node B. If yes, print "YES" (without quotes) else , print "NO"(without quotes).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int nodes,edges;
	cin>>nodes>>edges;

	vector<int> adjList[nodes+1];

	for(int i=0;i<edges;i++) {
		int nodeA,nodeB;
		cin>>nodeA>>nodeB;
		adjList[nodeA].push_back(nodeB);
    	adjList[nodeB].push_back(nodeA);
	}

	int queries;
	cin>>queries;
	for(int i=0;i<queries;i++) {
		int nodeA,nodeB;
		cin>>nodeA>>nodeB;
    
    bool isConnected = false;
    for(int j=0;j<adjList[nodeA].size();j++) if(adjList[nodeA][j] == nodeB) isConnected = true;
    
		string ans = isConnected ? "YES" : "NO";
		cout<<ans<<endl;
	}
}
