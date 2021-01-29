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
        visited.resize(graph.size());
        res.resize(graph.size());
        FORI(graph.size())
        {
            if(graph[i].size()) //if this node is not the terminal node
            {
                //going to its next node
                for(int i = 0 ; i < graph.size() ; i++)
                {
                    visited[i] = 0;
                }
                cycle_cnt = 0;
                printf("Start from:  %d \n",i);
                dfs(i, i, graph, 0); //directly go to its next node
                if(cycle_cnt == 0)
                {
                    res[i] = 1; //able to reserve
                } //this node gives no circle, that traverse back to itself satisfie the requirements
            }
            else
            {
                res[i] = 1;//directly push back it since such node is a terminal
            }
        }
        //EVERY NODE THAT CONNECTS TO THE NODE THAT PROBABLY FORM A CYCLE SHOULD ALSO BE ELIMINATED
        //DFS AGAIN TO FIND THE NODES THAT CONNECTS TO PART OF THE CYCLE (OR SAY MAY CRASH INTO CYCLE)
        FORI(graph.size())
        {
            if(graph[i].size()) //if this node is not the terminal node
            {
                printf("second Start from:  %d \n",i);
                for(int i = 0 ; i < graph.size() ; i++)
                {
                    visited[i] = 0;
                }
                dfs2_eliminate(i, i, graph, 0); //directly go to its next node
            }
        }
        vector<int> final_res;
        cout<<"Result size "<<res.size()<<endl;
        FORI(res.size())
        {
            cout<<res[i]<<endl;
            if(res[i] != -1)
            {
                final_res.push_back(i);
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
    void dfs2_eliminate(int cur_node, int start, vector<vector<int>> graph, int step)
    {
        int connect_to_circle = 0;
        for(int i = 0 ; i < graph[cur_node].size() ; i++)
        {
            for(int j = 0;j < form_cycle.size(); j++)
            {
                cout<<"graph "<<cur_node<<" connect to "<<graph[cur_node][i]<<"  form cycle  "<<form_cycle[j]<<endl;
                if(graph[cur_node][i] == j && form_cycle[j] == 1) //a given node is connected to a part of the cycle
                {
                    printf(" A node connect to the cycle formed!!!! %d \n",cur_node);
                    res[cur_node] = -1;
                    connect_to_circle = 1;
                    return;
                }

            }
            if(connect_to_circle)
                break;
        }

        traversed_path.push(cur_node);
        visited[cur_node] = 1;
        step++;
        if(connect_to_circle && step > 1)//a cycle formed
        {
            res[cur_node] = -1;
            return;
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
