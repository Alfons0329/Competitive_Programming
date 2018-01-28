class Solution
{
public:
    int numJewelsInStones(string jw, string st)
    {
        int cnt=0;
        for(int i=0;i<jw.size();i++)
        {
            for(int j=0;j<st.size();j++)
            {
                if(jw[i]==st[j])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        return cnt;
    }
};
