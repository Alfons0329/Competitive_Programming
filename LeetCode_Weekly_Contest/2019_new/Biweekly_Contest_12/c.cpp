#define MAX_N 10005
class Solution 
{
public:
    pair<int, int> bfs(vector<vector<int>>& adj_list, int start_node)
    {
        int dist = 0;
        vector<int> nodes_dist(MAX_N, -1);
        pair<int, int> res = make_pair(0, 0); // end, max_len
        
        nodes_dist[start_node] = 0;
        queue<int> q;
        q.push(start_node);
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            
            for(auto x : adj_list[cur])
            {
                if(nodes_dist[x] == -1) // not visited and has path towards it
                {
                    nodes_dist[x] = nodes_dist[cur] + 1; // add dist by 1 if can be visited from current node
                    if(nodes_dist[x] > res.second)
                    {
                        res = make_pair(x, max(res.second, nodes_dist[x]));
                    }
                    q.push(x);
                }
            }
        }
        
        return res;
    }
    
    int treeDiameter(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<vector <int> > adj_list;
        adj_list.resize(MAX_N);
        
        for(int i = 0; i < n; i++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        pair<int, int> border_point = bfs(adj_list, 0);
        pair<int, int> final_res = bfs(adj_list, border_point.first);
        return final_res.second;
    }
};