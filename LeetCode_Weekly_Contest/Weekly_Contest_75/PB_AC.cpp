#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<vector <int>>final_res;
    vector<int>res, visited;
    stack<int> traversed_path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) //graph in adjacency list
    {
        int dst;
        FORI(graph.size())
        {
            if(graph[i].size()==0)
            {
                dst = i;
            }
            visited.push_back(false);
        }
        dfs(0,dst,res,graph);
        return final_res;
    }
    void dfs(int cur_node, int dst, vector<int> res, vector<vector<int>> graph)
    {

        traversed_path.push(cur_node);
        visited[cur_node] = true;
        if(cur_node == dst)
        {

            stack<int> copied_stk = traversed_path;
            while(copied_stk.size())
            {
                res.push_back(copied_stk.top());
                copied_stk.pop();
            }
            reverse(res.begin(), res.end());

            final_res.push_back(res);
            res.clear();
            //return ;
        }
        else
        {

            FORI(graph[cur_node].size())
            {
                if(!visited[graph[cur_node][i]])
                {
                    dfs(graph[cur_node][i], dst, res, graph);
                }
            }
        }
        //back trace if there will be still some nodes have to be visited but now path are blocked since adj nodes are marked visited
        visited[cur_node] = false;
        cur_node = traversed_path.top();
        traversed_path.pop();
    }

};
