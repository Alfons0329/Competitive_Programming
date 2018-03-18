#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<int>res, visited;
    stack<int> traversed_path;
    int cycle_cnt;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
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
        return res;
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
                break;
            }
            else if(graph[cur_node][i] == cur_node)
            {
                printf(" A SELF cycle formed!!!! %d \n",cur_node);
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
