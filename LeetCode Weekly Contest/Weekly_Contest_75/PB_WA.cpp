#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {

        int target = 0;
        int pos = 0, total_size = 0;
        vector<int> res_part, output_deg;
        output_deg.resize(graph.size());
        vector<vector<int>> final_res;
        FORI(graph.size())
        {
            if(graph[i].size()==0)
            {
                target = i;
            }
            else
            {
                total_size+=graph[i].size();
                output_deg[i] = graph[i].size();
            }
        }
        int visited = 0, i=0, tmp, undone = 1;
        while(visited != total_size)
        {
            res_part.push_back(pos);
            if(output_deg[pos])
            {
                tmp = pos;
                pos = graph[pos][output_deg[pos]-1];
                output_deg[tmp]--;
                visited++;
            }
            else
            {
                FORI(output_deg.size())
                {
                    if(output_deg[i])
                        pos = output_deg[i];
                }
            }
            if(graph[pos].size()==0)
            {
                pos = 0;
                res_part.push_back(target);
                final_res.push_back(res_part);
                res_part.clear();
            }
        }
        return final_res;
    }

};
