#define mp make_pair
class Solution 
{
public:
    string alphabetBoardPath(string tg) 
    {
        vector<string>b = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        unordered_map<char, pair<int, int>>m; // char -> (row, col)
        
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < b[i].size(); j++)
            {
                m[b[i][j]] = mp(i, j);
            }
        }
        
        pair<int, int> last;
        pair<int, int> now;
        last = mp(0, 0);
        string res;
        for(auto s : tg)
        {
            now = m[s];
            int r = now.first, c = now.second;
            if(last == now)
            {
                res += "!";
            }
            else
            {
                int dr = r - last.first, dc = c - last.second;
                int postr = 0;
                
                for(int i = -1; i >= dr; i--)
                {
                    res += "U";
                }
                
                for(int i = 1; i <= dc; i++)
                {
                    res += "R";
                }
                
                for(int i = -1; i >= dc; i--)
                {
                    res += "L";
                }
                
                for(int i = 1; i <= dr; i++)
                {
                    res += "D";
                }
                res += "!";
            }
            last = now;
        }
        return res;
    }
};
