class Solution
{
public:
    int di[4] = {-1, 1, 0, 0}; // UDLR
    int dj[4] = {0, 0, -1, 1};
    struct node
    {
        int i, j, e;
        node(int i, int j, int e) : i(i), j(j), e(e) {}
    };
    int minimumEffortPath(vector<vector<int>> &h)
    {
        int r = h.size(), c = h[0].size(), i = 0, j = 0, res = 0;

        auto cmp = [&](node a, node b) -> bool {
            return a.e > b.e;
        };

        vector<vector<int>> efforts(105, vector<int>(105, INT_MAX)); // efforts[i][j] = effort from (0, 0) to (i, j)
        priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);   // priority queue for Dijkstra
        efforts[0][0] = 0;
        pq.push(node(0, 0, 0));

        while (pq.size())
        {
            i = pq.top().i, j = pq.top().j;
            int effort = pq.top().e;
            pq.pop();

            if (i == r - 1 && j == c - 1)
            {
                break;
            }

            // pruning the unwanted
            if (effort > efforts[i][j])
            {
                continue;
            }

            // scan the neighbors
            for (int k = 0; k < 4; k++)
            {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= r || nj >= c)
                {
                    continue;
                }

                // if current method has smaller cost
                if (max(efforts[i][j], abs(h[i][j] - h[ni][nj])) < efforts[ni][nj])
                {
                    efforts[ni][nj] = max(efforts[i][j], abs(h[i][j] - h[ni][nj]));
                    pq.push(node(ni, nj, max(efforts[i][j], abs(h[i][j] - h[ni][nj]))));
                }
            }
        }

        return efforts[r - 1][c - 1];
    }
};