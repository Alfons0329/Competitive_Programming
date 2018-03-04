//["XOX","O O","XOX"]
class Solution
{
public:
    int xcnt,ocnt;
    bool validTicTacToe(vector<string>& board)
    {
        xcnt=0;
        ocnt=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O')
                {
                    ocnt++;
                }
                else if(board[i][j]=='X')
                {
                    xcnt++;
                }
            }
        }
        if(xcnt==0 && ocnt==1)
        {
            cout<<1<<endl;
            return 0;
        }
        else if(xcnt>ocnt+1 || ocnt>xcnt+1)
        {
            cout<<2<<endl;
            return 0;
        }
        else if(ocnt > xcnt)
        {
            return 0;
        }
        else if(!checkwin(board))
        {
            cout<<3<<endl;
            return 0;
        }

        return 1;
    }
    bool checkwin(vector<string>& board)
    {
        int win_cnt=0;
        int xwin=0,owin=0;
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ')
            {
                cout<<4<<endl;
                if(board[i][0]=='X')
                {
                    xwin=1;
                }
                else
                {
                    owin=1;
                }
                win_cnt++;
            }
        }
        for(int i=0;i<3;i++)
        {
            if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' ')
            {
                cout<<5<<endl;
                if(board[0][i]=='X')
                {
                    xwin=1;
                }
                else
                {
                    owin=1;
                }
                win_cnt++;
            }
        }
        if(board[0][0]==board[1][1]
            && board[0][0]==board[2][2] && board[0][0]!=' ')
            {
                cout<<6<<endl;
                if(board[0][0]=='X')
                {
                    xwin=1;
                }
                else
                {
                    owin=1;
                }
                win_cnt++;
            }
        if(board[0][2]==board[1][1]
            && board[0][2]==board[2][0] && board[0][2]!=' ')
            {
                cout<<7<<endl;
                if(board[0][2]=='X')
                {
                    xwin=1;
                }
                else
                {
                    owin=1;
                }
                win_cnt++;
            }
        cout<<win_cnt<<" , "<<xcnt<<" , "<<ocnt<<endl;
        if(win_cnt==0)
                return 1;
        else if(win_cnt==1)
        {
            if(xwin)
            {
                if(ocnt>=xcnt)
                {
                    return 0;
                }
                else if(xcnt==ocnt+1)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if(owin)
            {
                if(ocnt<xcnt)
                {
                    return 0;
                }
                else if(xcnt==ocnt)
                {
                    return 1;
                }
                else if(ocnt>xcnt)
                {
                    return 0;
                }
            }

        }
        else
        {
            return 0;
        }
    }
};
