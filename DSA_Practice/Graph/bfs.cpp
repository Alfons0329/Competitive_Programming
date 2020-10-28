#include <bits/stdc++.h>
#define MAX_N 105 // max count of nodes
using  namespace  std;

vector<vector<int>> adj(MAX_N, vector<int>(0, 0)); // adjacency list
vector<int> vis(MAX_N, 0); // visited node
// add edge from u to v (undirected)
void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u); // comment out for directed graph
}

void bfs_iter(int u){
    int iter_cnt = 0;
    queue<int> q;
    q.push(u);
    vis[u] = 1;

    while(q.size()){
        u = q.front(); // pop out the current node
        printf("vis %d \n", u);
        q.pop();


        // search the next node to visit and push into the traverse stack
        for(int v : adj[u]){
            if(!vis[v]){
                q.push(v);
                printf("push %d \n", v);
                vis[v] = 1;
            }
        }
        iter_cnt++;
    }
    printf("iter cnt %d \n", iter_cnt);
}

int main(){

    add_edge(0, 1);
    add_edge(0, 4);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(3, 5);
    add_edge(2, 8);
    add_edge(8, 9);
    add_edge(6, 9);
    add_edge(6, 5);
    add_edge(5, 7);

    fill(vis.begin(), vis.end(), 0);
    printf("-----iterative-----\n");
    bfs_iter(0);

    return 0;
}
