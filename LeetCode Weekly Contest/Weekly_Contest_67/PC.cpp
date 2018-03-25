class Solution
{
public:
    int orderOfLargestPlusSign(int MAXN, vector<vector<int>>& mines)
    {
        int order = 0, count = mines.size();
        vector<vector<int>>dp_up, dp_down, dp_left, dp_right;
        //initialize
        for (size_t i = 0; i < count; i++)
        {
            fill(dp_up[i].begin(), dp_up[i].end(), 1);
            fill(dp_down[i].begin(), dp_down[i].end(), 1);
            fill(dp_left[i].begin(), dp_left[i].end(), 1);
            fill(dp_right[i].begin(), dp_right[i].end(), 1);
        }
        for (size_t i = 0; i < count; i++)
        {
            dp_up[mines[i][0]][mines[i][1]] = 0;
            dp_down[mines[i][0]][mines[i][1]] = 0;
            dp_left[mines[i][0]][mines[i][1]] = 0;
            dp_right[mines[i][0]][mines[i][1]] = 0;
        }

        //main dynamic programming
        //up continuous (bottom up)
        for(int i = 0;i < MAXN; i++)
        {
            for(int j = MAXN - 2;j >= 0; j--)
            {

            }
        }
        //down continuous (top down)
        //left continuous
        //right continuous
    }

};
