#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */


void dfs(vector<vector <int> > edges, vector<bool> visited, vector<long> ids, int cur_id, int& res, int cur_len, int val)
{
    // printf("cur_id %d cur_color %ld cur_len %d target %d\n", cur_id, ids[cur_id - 1], cur_len, val);
    visited[cur_id] = true;// mark current node as traversed

    // if the color of current node is what we want, update the result, but NO NEED TO RETURN 
    // since there will be other path not visited, go to the other path will be suitable.

    int n = edges[cur_id].size();// how many mnodes are "being connected" by current node?
    if(ids[cur_id - 1] == val && cur_len > 0)
    {
        res = min(res, cur_len);
        // printf("update res to %d\n", res);
        cur_len = 0;
        // restart from current node

        for(int i = 0; i < n; i++)
        {
            if(!visited[edges[cur_id][i]]) // if untraversed
            {
                dfs(edges, visited, ids, edges[cur_id][i], res, cur_len + 1, val);
            }
        }
    }
    else
    {
        // keep searching
        for(int i = 0; i < n; i++)
        {
            if(!visited[edges[cur_id][i]]) // if untraversed
            {
                dfs(edges, visited, ids, edges[cur_id][i], res, cur_len + 1, val);
            }
        }    
    }
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) 
{
    // init 
    int res = INT_MAX;
    int m = graph_from.size(); // edge size
    int n = ids.size(); // node size 
    vector<vector<int>> edges(n + 1, vector<int>()); // edge relations of node_1 -> node_2 -> node_3, n + 1 for padding one base
    unordered_map<int, int> color_cnt;
    vector<bool> visited(n + 1, false);

    // make adjacent list
    for(int i = 0; i < m; i++)
    {
        // printf("edge i %d\n", i);
        edges[graph_from[i]].push_back(graph_to[i]); // make the edge relations
        edges[graph_to[i]].push_back(graph_from[i]); // make the edge relations
    }

    // unit test check whether the edge relationship is right
    for(int i = 1; i < n + 1; i++)
    {
        // printf("%d connects to ", i);
        for(int j = 0; j < edges[i].size(); j++)
        {
            // printf("%d ", edges[i][j]);
        }
        // printf("\n");
    }

    // find the starting node of that color
    int start_id = -1;
    for(int i = 0 ; i < n; i++)
    {
        color_cnt[ids[i]]++;
        // printf("color %d has cnt %d\n", ids[i], color_cnt[ids[i]]);
        if(ids[i] == val)
        {
            start_id = i + 1;
        }
    }

    // starting dfs
    if(color_cnt[start_id] == 1 || start_id == -1) //only one for that color, return -1 directly or no such color
    {
        // printf("only one such color\n");
        return -1;
    }
    // printf("start id %d with color %d\n", start_id, ids[start_id - 1]);
    dfs(edges, visited, ids, start_id, res, 0, val);
    printf("res %d \n", res == INT_MAX ? -1 : res);
    return res == INT_MAX ? -1 : res;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
            });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

