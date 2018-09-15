class Solution
{
public:
    int kthGrammar(int nin, int kin)
    {
        int cnt = 0;
        kin--;
        while(kin)
        {
            if(kin&1)
            {
                cnt++;
            }
            kin>>=1;
        }
        return cnt&1;
    }
};
