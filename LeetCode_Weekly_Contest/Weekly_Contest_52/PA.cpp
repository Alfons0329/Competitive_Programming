#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
class Solution {
public:
    int repeatedStringMatch(string A, string B)
    {
        if(B==A)
            return 1;
        int cnt=0;
        string str="";
        while(1)
        {
            str+=A;
            cnt+=1;
            std::size_t found = str.find(B);
            if(cnt>=2&& str.size()>B.size())
            {
                if (found!=std::string::npos)
                    break;
                else
                    return -1;
            }
            if (found!=std::string::npos)
                break;
        }
        return cnt;
    }
};
