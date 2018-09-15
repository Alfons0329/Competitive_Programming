#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution {
public:
    vector<int> res;

    int slidingPuzzle(vector<vector<int>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==0)
                {
                    check(board,i,j,0);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        FORI(res.size())
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return res[0];
    }
    void check(vector<vector<int>>& board, int i, int j, int cnt)
    {
        if(i>=0&&i<2&&j>=0&&j<3)
        {
            cout<<"i and j "<<i<<","<<j<<endl;
            FORI(2)
            {
                for(int j=0;j<board[0].size();j++)
                    cout<<board[i][j]<<" ";
            }
            vector<vector<int>> ans{{1,2,3},{4,5,0}};
            if(board==ans)
            {
                res.push_back(cnt);
                return;
            }
            else
            {
                if(j!=0)
                {
                    swap(board[i][j],board[i][j-1]);
                    check(board,i,j-1,cnt+1);
                }

                if(j!=2)
                {
                    swap(board[i][j],board[i][j+1]);
                    check(board,i,j+1,cnt+1);
                }

                if(i==1)
                {
                    swap(board[i][j],board[i-1][j]);
                    check(board,i-1,j,cnt+1);
                }
                if(i==0)
                {
                    swap(board[i][j],board[i+1][j]);
                    check(board,i+1,j,cnt+1);
                }
            }
        }
        else
            return;
    }
};
