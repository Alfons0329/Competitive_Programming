
            class Solution {
            public:

                bool exist(vector<vector<char>>& board, string word)
                {
                    int rowBorder=board.size(),colBorder=board[0].size();
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
                    if(!rowBorder||!colBorder)
                        return false;

                    for(int row=0;row<rowBorder;row++)
                    {
                        for(int col=0;col<colBorder;col++)
                        {
                            if(backTrackingDFS(board,word,visited,row,col,0))
                                return true;
                        }
                    }
                    return false; //default condition ***Very important in backtracking algorithm***
                }
                bool backTrackingDFS(vector<vector<char>>& board, string word,vector<vector<bool> >&visited,int row,int col,int len) //use backTrackingDFS to DFS the grid and find what word we want
                {
                     if(row>=board.size()||col>=board[0].size()||row<0||col<0||visited[row][col]||(board[row][col]!=word[len]))//out of border or reached the used one
                        return false;
                     //or cant move further

                     if(len==word.length()-1)//find word done
                         return true;

                     visited[row][col]=true; //marked the traversed area as true
                     //4 directions
                     if(backTrackingDFS(board,word,visited,row-1,col,len+1))
                        return true;
                     if(backTrackingDFS(board,word,visited,row+1,col,len+1))
                        return true;
                     if(backTrackingDFS(board,word,visited,row,col-1,len+1))
                        return true;
                     if(backTrackingDFS(board,word,visited,row,col+1,len+1))
                        return true;

                    visited[row][col]=false;//try again
                    return false;
                }
            };
