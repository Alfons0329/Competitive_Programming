class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) 
    {
        //check which node be removed will remove the most connection
        int n = initial.size(), m = graph.size();
        sort(initial.begin(), initial.end());
        vector<int> color_cnt(n,0);
        
        //count how much nodes can be traversed from the starting point
        for(int i = 0; i < n; ++i)
        {
            int each_cnt = 0;
            vector<bool> traversed(m, false);
            // printf("start from %d \n", initial[i]);
            DFS(graph, initial[i], traversed, each_cnt);
            color_cnt[i] = each_cnt;
            // printf("Node %d, reaches %d \n", initial[i], each_cnt);
        }
        int res = INT_MAX, max_color = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(color_cnt[initial[i]] >= max_color)
            {
                res = initial[i];
                max_color = color_cnt[initial[i]];
            }
        }
        return res;
    }
    void DFS(vector<vector<int>>& graph, int cur_node, vector<bool>& traversed, int& each_cnt)
    {
        if(traversed[cur_node]) //traversed node, return
        {
            return;
        }
        // printf("traverse to %d \n", cur_node);
        traversed[cur_node] = true;
        each_cnt++;
        for(int i = 1; i < graph[cur_node].size(); ++i)
        {
            if(graph[cur_node][i]) //traversable and not traversed, travese it
            {
                DFS(graph, i, traversed, each_cnt);
            }
        }
        return; //end traverse of current node
    }
};
