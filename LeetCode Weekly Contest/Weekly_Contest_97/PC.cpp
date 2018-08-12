class Solution
{
public:
    bool is_bipartie;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) //dislike act as adjacent matrix
    {
        int visited[N + 1] , visit_cnt; //visited matrix. -1 as unvisited, 0 as color1, 1 as color2
        memset(visited, -1, sizeof(visited));

        is_bipartie = true;
        dfs(1, 0, visited, dislikes);

        for(int i = 1 ;i <= N ;i++)
        {
            // printf("vertex %d color %d \n", i, visited[i]);
        }
        return is_bipartie;
    }
    void dfs(int cur_vertex,int cur_color, int* visited, vector<vector<int>>& dislikes)
    {
        visited[cur_vertex] = cur_color;
        // printf("go %d \n", cur_vertex);
        for(int i = 0; i < dislikes.size(); i++)
        {
            if(dislikes[i][0] == cur_vertex) //check if unvisited and is the path of current vertex
            {
                if(visited[dislikes[i][1]] == -1) //unvisited
                {
                    dfs(dislikes[i][1], cur_color == 1 ? 0 : 1 /*change the color for adjacent vertices*/, visited, dislikes);
                }
                else if(visited[dislikes[i][1]] == cur_color)
                {
                    is_bipartie = false;
                }
            }
        }
    }

};
