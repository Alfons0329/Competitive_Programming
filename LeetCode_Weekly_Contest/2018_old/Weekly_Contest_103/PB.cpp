class Solution {
public:
    vector<int>possi;
    int len;
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        len = board.size();
        int res = 0x7FFF;
        unordered_map<int, pair<int, int>> mymap; //store the relationship
        for(int i = len - 1; i >= 0; i--)
        {
            if((i + 1) % 2 == 0)
            {
                for(int j = 0; j < len; j++)
                {
                    mymap[(len - i - 1) * len + j + 1] = make_pair(i, j);
                }   
            }
            else
            {
                for(int j = len - 1; j >= 0; j--)
                {
                    mymap[(len - i - 1) * len + (len - j)] = make_pair(i, j);
                }
            }
        }
        int num = 1;
        BFS(board, mymap, len - 1, 0, len * len, 0, 1);
        for(int i = 0; i < possi.size(); i++)
        {
            if(possi[i] == -1)
            {
                return -1;
            }
            res = min(possi[i], res);
        }
        return res;
    }
    void BFS(vector<vector<int>>& board, unordered_map<int, pair<int, int>> mymap, int row, int col, int dst,int step, int num)
    {
        if(num >= dst) //end
        {
            possi.push_back(step);
            printf("end!! step %d\n", step);
            return; 
        }
        
        int jmp_flg = 0;
        row = mymap[num].first; //num -> row 
        col = mymap[num].second; //num -> col
        if(board[row][col] >= 1)//jump
        {
            printf("jump from %d", num);
            num = board[row][col];
            printf(" to %d \n",num);
            jmp_flg = 1;
        }
        board[row][col] = 0; //mark as traversed;
        printf("num %d row %d col %d step %d \n",num, row, col, step);
        
        if(jmp_flg && board[row][col] >= 1)
        {
            possi.push_back(-1);    
            return;
        }
        jmp_flg = 0;
        
        // printf("i ok : ");
        for(int i = 1; i <= 6; i++)
        {
            if(board[mymap[num + i].first][mymap[num + i].second] >= 1)
            {
                BFS(board, mymap, row, col, dst, step + 1, num + i);
            }
        }
        BFS(board, mymap, row, col, dst, step + 1, num + 6);
        // printf("\n");
        return;
    }
};