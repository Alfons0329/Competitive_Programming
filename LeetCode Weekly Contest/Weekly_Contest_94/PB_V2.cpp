class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int posx = 0, posy = 0, dir = 0, ans = 0, tmpx = 0, tmpy = 0; //0 north 1 east 2 south 3 west
        int cango = 1;
        set<pair<int, int>> obst_set;
        for(auto &it : obstacles)
        {
            obst_set.insert(make_pair(it[0], it[1]));
        }
        for(int i = 0; i < commands.size(); i++)
        {
            if(commands[i] == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if(commands[i] == -2)
            {
                if(dir == 0)
                {
                    dir = 3;
                }
                else
                {
                    dir--;
                    dir %= 4;
                }
            }
            else
            {
                for(int j = 0; j < commands[i] ;j++) //move grid one by one
                {
                    tmpx = posx + dx[dir];
                    tmpy = posy + dy[dir];
                    if(obst_set.find(make_pair(tmpx, tmpy)) != obst_set.end())
                    {
                        break;
                    }
                    else
                    {
                        posx = tmpx;
                        posy = tmpy;
                    }
                }
            }
            ans = max(ans, posx * posx + posy * posy);
        }
        return ans;
    }
};
