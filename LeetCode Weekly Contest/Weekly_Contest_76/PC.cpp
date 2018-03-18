#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<int> res, visited;
    vector<int> form_cycle;
    stack<int> traversed_path;
    int cycle_cnt;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        FORI(graph.size())
        {
            form_cycle.push_back(0);
        }
        FORI(graph.size())
        {
            if(graph[i].size()) //if this node is not the terminal node
            {
                //going to its next node
                for(int i = 0 ; i < graph.size() ; i++)
                {
                    visited.push_back(0);
                }
                cycle_cnt = 0;
                printf("Start from:  %d \n",i);
                dfs(i, i, graph, 0); //directly go to its next node
                if(cycle_cnt == 0)
                {
                    res.push_back(i);
                } //this node gives no circle, that traverse back to itself satisfie the requirements
            }
            else
            {
                res.push_back(i);//directly push back it since such node is a terminal
            }
        }
        //EVERY NODE THAT CONNECTS TO THE NODE THAT PROBABLY FORM A CYCLE SHOULD ALSO BE ELIMINATED
        cout<<"Form cycle : ";
        FORI(form_cycle.size())
        {
            cout<<form_cycle[i]<<" ";
        }
        cout<<endl;
        FORI(graph.size())
        {
            for(int j = 0 ; j < graph[i].size() ; j++)
            {
                for(int k = 0 ; k < form_cycle.size() ; k++)
                {
                    cout<<" i "<<i<<" j "<<j<<" k "<<k<<endl;
                    if(graph[i][j] == k && form_cycle[k])
                    {
                        cout<<"ELIMINATE "<<k<<endl;
                        res[i] = -1;
                        break;
                    }
                }
            }

        }
        vector<int> final_res;
        FORI(res.size())
        {
            cout<<res[i]<<endl;
            if(res[i] != -1)
            {
                final_res.push_back(res[i]);
            }
        }
        return final_res;
    }
    void dfs(int cur_node, int start, vector<vector<int>> graph,int step)
    {
        traversed_path.push(cur_node);
        visited[cur_node] = 1;
        step++;
        printf("Now traversed use DFS to %d \n",cur_node);
        int check_next_is_start_cycle = 0;
        FORI(graph[cur_node].size()) //jump beforehand
        {
            if(graph[cur_node][i] ==  start && step > 1)
            {
                check_next_is_start_cycle = 1;
                form_cycle[start] = 1;
                break;
            }
            else if(graph[cur_node][i] == cur_node)
            {
                printf(" A SELF cycle formed!!!! %d \n",cur_node);
                form_cycle[cur_node] = 1;
                check_next_is_start_cycle = 1;
                break;
            }
        }
        /*if(graph[cur_node].size() == 1 && graph[cur_node][0] == cur_node)//self cycle
        {

            cycle_cnt++;
        }*/
        if(check_next_is_start_cycle)//a cycle formed
        {
            printf(" A cycle formed!!!! %d \n",cur_node);
            cycle_cnt++;
        }
        else
        {
            FORI(graph[cur_node].size()) //search the next node that can be traversed from the current node
            {
                if(!visited[graph[cur_node][i]])
                {
                    dfs(graph[cur_node][i], start, graph, step);
                }
            }
        }
        visited[cur_node] = false; //reach end and back track to find the next
        cur_node = traversed_path.top();
        cout<<"Back trace to "<<cur_node<<endl;
        traversed_path.pop();
    }
};
