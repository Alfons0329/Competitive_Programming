class Solution
{
public:
    int orderOfLargestPlusSign(int MAXN, vector<vector<int>>& mines)
    {
        int order = 0, count = mines.size();
        vector<vector<int>>dp_up(MAXN, vector<int>(MAXN, 1)),
        dp_down(MAXN, vector<int>(MAXN, 1)),
        dp_left(MAXN, vector<int>(MAXN, 1)),
        dp_right(MAXN, vector<int>(MAXN, 1)),
        dp_ans(MAXN, vector<int>(MAXN, 0));
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
                if(dp_up[j][i] == 1)
                {
                    dp_up[j][i] = dp_up[j + 1][i] + 1;
                }
            }
        }
        //down continuous (top down)
        for(int i = 0;i < MAXN; i++)
        {
            for(int j = 1;j < MAXN; j++)
            {
                if(dp_down[j][i] == 1)
                {
                    dp_down[j][i] = dp_down[j - 1][i] + 1;
                }
            }
        }
        //left continuous
        for(int i = 0;i < MAXN; i++)
        {
            for(int j = MAXN - 2;j >=0 ;j--)
            {
                if(dp_left[i][j] == 1)
                {
                    dp_left[i][j] = dp_left[i][j + 1] + 1;
                }
            }
        }
        //right continuous
        for(int i = 0;i < MAXN; i++)
        {
            for(int j = 1;j < MAXN; j++)
            {
                if(dp_right[i][j] == 1)
                {
                    dp_right[i][j] = dp_right[i][j - 1] + 1;
                }
            }
        }

        //check for direction since the plus sign has to satisfiy all the four direction, if one of the direction fails. it has to decrease to that direction
        for(int i = 0; i < MAXN; i++)
        {
            for(int j = 0; j < MAXN; j++)
            {
                dp_ans[i][j] = min(min(dp_up[i][j], dp_down[i][j]), min(dp_left[i][j], dp_right[i][j]));
                if(dp_ans[i][j] > order)
                {
                    order = dp_ans[i][j];
                }
            }
        }

        return order;
    }

};
