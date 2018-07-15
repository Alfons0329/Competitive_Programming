#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    int binaryGap(int num)
    {
        string binstr = to_binary(num);
        cout << binstr <<endl;
        vector<int> pos;
        int maxd = 0;
        for(int i = 0; i < binstr.size() - 1; i++)
        {
            if(binstr[i] == '1')
            {
                for(int j = i + 1; j < binstr.size(); j++)
                {
                    if(binstr[j] == '1')
                    {
                        maxd = max(maxd, j - i);
                        printf("csc i %d j %d\n", i, j);
                        i = j;
                        break;
                    }
                }
            }
        }
        return maxd;
    }
    string to_binary(int num)
    {
        string res;
        while(num)
        {
            if(num & 1)
            {
                res += "1";
            }
            else
            {
                res += "0";
            }
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
