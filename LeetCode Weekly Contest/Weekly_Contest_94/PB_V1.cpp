class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int posx = 0, posy = 0, dir = 0, ans = 0; //0 north 1 east 2 south 3 west
        int cango = 1;
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
                cango = 1;
                for(int j = 0; j < obstacles.size(); j++)
                {
                    switch (dir)
                    {
                        case 0:
                        {
                            if(posx == obstacles[j][0])
                            {
                                if(posy < obstacles[j][1] && posy + commands[i] >= obstacles[j][1])
                                {

                                    posy = obstacles[j][1] - 1;
                                    cango = 0;
                                }
                            }
                            break;
                        }
                        case 1:
                        {
                            if(posy == obstacles[j][1])
                            {
                                if(posx < obstacles[j][0] && posx + commands[i] >= obstacles[j][0])
                                {
                                    posx = obstacles[j][0] - 1;

                                    cango = 0;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            if(posx == obstacles[j][0])
                            {
                                if(posy > obstacles[j][1] && posy - commands[i] <= obstacles[j][1])
                                {
                                    posy = obstacles[j][1] + 1;

                                    cango = 0;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            if(posy == obstacles[j][1])
                            {
                                if(posx > obstacles[j][0] && posx - commands[i] <= obstacles[j][0])
                                {
                                    posx = obstacles[j][0] + 1;

                                    cango = 0;
                                }
                            }
                            break;
                        }
                        cout << endl;
                        default: break;
                    }
                    if(cango == 0)
                    {
                        break;
                    }
                }
                if(cango)
                {
                    switch (dir)
                    {
                        case 0:
                        {

                            posy += commands[i];
                            break;
                        }
                        case 1:
                        {

                            posx += commands[i];
                            break;
                        }
                        case 2:
                        {

                            posy -= commands[i];
                            break;
                        }
                        case 3:
                        {

                            posx -= commands[i];
                            break;
                        }
                        default: break;
                    }
                }
            }
            ans = max(ans, posx * posx + posy * posy);
        }
        return ans;
    }
};
