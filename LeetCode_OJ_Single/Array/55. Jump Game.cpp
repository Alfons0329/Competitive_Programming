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
#define LL long long
#define ll __int64
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
    bool stop=false;
    bool canJump(vector<int>& nums)
    {
        int pos=0;
        for(int i=0;i<nums.size();)
        {
            if(!nums[i])
            {
                stop=true;
                break;
            }
            else
            {

                if(pos==nums.size()-1)
                {
                    break;
                }
                else
                {
                    pos+=nums[i];
                    //cout<<"i is now"<<i<<endl;
                    i=pos;
                    //cout<<"Pos is now"<<pos<<endl;
                }
            }
        }
        if(stop)
        {
            if(pos>=nums.size()-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(pos>=nums.size()-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
int main()
{
    int tmp;
    Solution sol;
    vector<int>data;
    while(cin>>tmp)
    {
        data.push_back(tmp);
    }
    cout<<sol.canJump(data);
    return 0;
}

