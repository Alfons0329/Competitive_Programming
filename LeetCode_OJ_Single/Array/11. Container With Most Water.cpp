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
    int maxArea(vector<int>& height)
    {
        int i=0,j=height.size()-1,maxa=min(height[i],height[j])*abs(i-j);//maxa 是給DP用的 將當前的最大面積植儲存起來
        if(height.size()<=2)
        {
            return min(height[i],height[j])*abs(i-j);
        }
        else
        {
            while(1)
            {

                if(height[i]>height[j]) //如果左邊大於右邊，就將右邊移過來看有沒有更高的右端，再將最大的面積更新與否
                {
                    maxa=max(maxa,min(height[i],height[j-1])*abs(j-1-i));//動態規劃
                    //先將上一次的結果存起來和這一次要執行的面積做比較，看看哪個較大就存哪個擇優，一陸找下去更新最大值
                    //這就是動態規劃的核心RRRRRRRRRRRRRRR
                    j--;
                }
                else//如果左邊大於右邊，就將左邊移過來看有沒有更高的左端，再將最大的面積更新與否
                {
                    maxa=max(maxa,min(height[i+1],height[j])*abs(j-1-i));
                    i++;
                }
                if(i==j)//終止條件為相遇，代表已經掃過一輪，再繼續下去只是重複做罷了
                {
                    return maxa;
                    break;
                }
            }
        }

    }

};
int main()
{
    Solution sol;
    vector <int>data;
    int tmp;
    while(cin>>tmp)
    {
        data.push_back(tmp);

    }
    cout<<sol.maxArea(data);
    return 0;
}
