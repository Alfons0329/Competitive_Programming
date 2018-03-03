#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    bool isIdealPermutation(vector<int>& arr)
    {
        int gbi=0,lci=0,cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(i<=arr.size()-2)
            {
                for(int j=i+2;j<arr.size();j++)
                {
                    if(arr[i]>arr[j])
                    {
                        cnt++;
                    }
                }
            }
            if(arr[i]>arr[i+1])
            {
                lci++;
            }
        }
        gbi=cnt+lci;
        return (gbi==lci);
    }
};
