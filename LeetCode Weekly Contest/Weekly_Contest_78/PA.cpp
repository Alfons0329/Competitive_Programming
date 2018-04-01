#define FORI(n) for(int i = 0; i < n; ++ i)
#define pb push_back
#include <cstdlib>
class Solution
{
public:
    vector<string> subdomainVisits(vector<string>& cpdomains)
    {
        map<string ,int> mymap;
        vector<vector <int> > dotpos;
        vector<int> visit; //each domain visit
        dotpos.resize(cpdomains.size());
        //cpdomains[i].size() - 1
        FORI(cpdomains.size())
        {
            for(int j = cpdomains[i].size() - 1;j >= 0;j--)
            {
                if(cpdomains[i][j] == '.')
                {
                    dotpos[i].pb(j);
                }
                else if(cpdomains[i][j] == ' ')
                {
                    dotpos[i].pb(j);
                    break;
                }
            }
        } //subdomain pos
        string tmp;
        FORI(cpdomains.size())
        {
            for(int j = 0;j < cpdomains[i].size();j++)
            {
                if(cpdomains[i][j] == ' ')
                {
                    tmp = cpdomains[i].substr(0,j + 1);
                    int tmp2 = stoi(tmp);
                    visit.pb(tmp2);
                    break;
                }
            }
        } //times
        int poscnt = 0;
        FORI(cpdomains.size())
        {
            for(int j = 0;j < dotpos[i].size(); j++)
            {
                tmp = cpdomains[i].substr(dotpos[i][j] + 1, cpdomains[i].size() - dotpos[i][j] + 1);
                mymap[tmp] += visit[i];
            }
        }//accumulate

        vector<string> res;
        string timestr;
        for(map<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        {
            timestr = to_string(it->second);
            res.pb(timestr + " " + it->first);
        }
        return res;
    }
};
