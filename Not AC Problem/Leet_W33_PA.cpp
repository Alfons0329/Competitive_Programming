#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        int cnt=1,max=0,min=0,pmx,pmn;
        vector<int>res;
        for (int i = 0; i < nums.size(); i++)
        {
            max=nums[i];
            min=nums[i];
            cnt=1;
            for(int j=i+1;j < nums.size(); j++)
            {
                if(nums[j]>=max)
                {
                    if(nums[j]-min==1)
                    {
                        max=nums[j];
                        cnt++;
                        //cout<<"type 1 Max and min "<<max<<" and "<<min<<" i "<<i<<"and j "<<j<<endl;
                    }

                }
                else if(nums[j]<=min)
                {
                    if(max-nums[j]==1)
                    {
                        min=nums[j];
                        cnt++;
                        //cout<<"Max and min "<<max<<" and "<<min<<" i "<<i<<"and j "<<j<<endl;
                    }

                }

            }
            //cout<<"CNT IS NOW "<<cnt<<endl;
            res.push_back(cnt);
        }
        if(nums.size())
        {
            sort(res.begin(),res.end());
            return (res.back()>1)?res.back():0;
        }
        else
        {
            return 0;
        }

    }
};
// main for debugging purpose
int main()
{
    Solution sol;
    vector<int> tc;
    int tmp;
    while(cin>>tmp)
    {
        tc.push_back(tmp);
    }
    cout<<"Ans is"<<sol.findLHS(tc)<<endl;
    return 0;
}
