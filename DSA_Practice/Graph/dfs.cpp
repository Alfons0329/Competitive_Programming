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

void dfs_recur(int u){
    printf("vis %d \n", u);
    vis[u] = 1;

    // search the next node to visit and do recursion on it
    for(int v : adj[u]){
        if(!vis[v]){
            dfs_recur(v);
        }
    }
}

void dfs_iter_1(int u){
    int iter_cnt = 0;
    stack<int> s;
    s.push(u);
    vis[u] = 1;

    while(s.size()){
        u = s.top(); // pop out the current node
        printf("vis %d \n", u);
        s.pop();


        // search the next node to visit and push into the traverse stack
        for(int v : adj[u]){
            if(!vis[v]){
                s.push(v);
                printf("push %d \n", v);
                vis[v] = 1;
            }
        }
        iter_cnt++;
    }
    printf("iter_1 cnt %d \n", iter_cnt);
}

void dfs_iter_2(int u){
    int iter_cnt = 0;
    stack<int> s;
    s.push(u);

    while(s.size()){
        u = s.top(); // pop out the current node
        if(!vis[u]){
            printf("vis %d \n", u);
            vis[u] = 1;
        }
        s.pop();

        // search the next node to visit and push into the traverse stack
        for(int v : adj[u]){
            if(!vis[v]){
                s.push(v);
            }
        }
        iter_cnt++;
    }
    printf("iter_2 cnt %d \n", iter_cnt);
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

    printf("-----recursive-----\n");
    // dfs_recur(0);
    fill(vis.begin(), vis.end(), 0);
    printf("-----iterative-----\n");
    dfs_iter_1(0);
    fill(vis.begin(), vis.end(), 0);
    dfs_iter_2(0);

    return 0;
}
