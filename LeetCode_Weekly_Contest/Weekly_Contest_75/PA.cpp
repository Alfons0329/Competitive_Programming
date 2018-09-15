#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    bool rotateString(string aa, string bb)
    {
        string tmp=aa;
        string tmp2;
        FORI(aa.size())
        {
            tmp2=tmp[0];
            tmp = tmp.substr(1,aa.size()-1);
            tmp+=tmp2;
            if(tmp == bb)
                return 1;
        }
        return 0;
    }
};
