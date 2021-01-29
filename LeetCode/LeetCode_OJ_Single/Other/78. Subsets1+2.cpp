#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAXN 1010000
#define ll long long
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
using namespace std;
ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
ll powmod(ll a, ll b, ll MOD){ ll ans = 1; while (b){ if (b % 2)ans = ans*a%MOD; a = a*a%MOD; b /= 2; }return ans; }
double dpow(double a, ll b){ double ans = 1.0; while (b){ if (b % 2)ans = ans*a; a = a*a; b /= 2; }return ans; }
class Solution {
public:

    vector<string>tempans;
    vector<vector<int> >finalans;
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        int bin;
        bin=pow(2,nums.size());
        sort(nums.begin(),nums.end());
        for(int i=0;i<bin;i++)
        {
            tempans.push_back(bitstring2subsets(nums,i));
        }
        set<string>tempans_in_set(tempans.begin(),tempans.end());//去除重複的
        //cout<<"step 1"<<endl;
        vector<string>tempans_after_set(tempans_in_set.begin(),tempans_in_set.end()); //在塞回vector中作為轉換
        //cout<<"step 2"<<endl;
        finalans.resize(tempans_after_set.size()); //最後將轉換好的vector由字串貼回整數容器中
        for(int i=0;i<finalans.size();i++)
        {
            for(int j=0;j<tempans_after_set[i].size();j++)
            {

                finalans[i].push_back(tempans_after_set[i][j]-'0');
            }
        }
        return finalans;
    }
    string bitstring2subsets(vector<int>& nums,int bin)
    {
        string tempreturn;
        for(int i=0;i<nums.size();i++)
        {
            if(bin&1)
            {
                tempreturn+=nums[i]+'0';
            }
            bin>>=1;
        }
        return tempreturn;

    }

};
int main()
{
    Solution sol;
    vector<int> data;
    int tmp;
    int tcase;
    cin>>tcase;
    for(int i=0;i<tcase;i++)
    {
        cin>>tmp;
        data.push_back(tmp);

    }
    vector<vector<int>  >ans=sol.subsetsWithDup(data);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
        cout<<"\n";
    }
    return 0;
}
