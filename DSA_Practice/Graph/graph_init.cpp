#include <bits/stdc++.h>
#define MAX_N 105 // max count of nodes
using  namespace  std;

vector<vector<int>> adj(MAX_N, vector<int>(0, 0));

// add edge from u to v (undirected)
void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u); // comment out for directed graph
}

int main(){

    add_edge(0, 1);
    add_edge(0, 4);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 3);
    add_edge(3, 4);

    return 0;
}