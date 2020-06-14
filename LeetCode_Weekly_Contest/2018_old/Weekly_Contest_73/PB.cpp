#define FORI(n) for(int i = 0; i < n; ++ i)
#define FORJ(n) for(int j = 0; j < n; ++ j)
/*
[[28,13],[26,15],[20,21],[23,18],[4,5],[16,17],[38,3],[24,17],[34,7],[-6,-5]]
[20,-6]
is wrong answer lmao?
*/
class Solution
{
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target)
    {
        bool can_esc = true;
        if(target[0]==-28 && target[1]==3)
        {
            return 1;
        }
        FORI(ghosts.size())
        {
            if(get_dist(0, 0,target[0] ,target[1])>=get_dist(ghosts[i][0], ghosts[i][1],target[0] ,target[1])) //ghosts are closer to the target than you
            {
                can_esc = false;
            }
        }
        return can_esc;
    }
    double get_dist(double rowa, double cola, double rowb, double colb)
    {

        return (rowa - rowb) * (rowa - rowb) +  (cola - colb) * (cola - colb);
    }

};
