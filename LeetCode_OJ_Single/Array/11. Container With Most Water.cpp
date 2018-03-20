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
        int i=0,j=height.size()-1,maxa=min(height[i],height[j])*abs(i-j);//maxa �O��DP�Ϊ� �N��e���̤j���n���x�s�_��
        if(height.size()<=2)
        {
            return min(height[i],height[j])*abs(i-j);
        }
        else
        {
            while(1)
            {

                if(height[i]>height[j]) //�p�G����j��k��A�N�N�k�䲾�L�Ӭݦ��S���󰪪��k�ݡA�A�N�̤j�����n��s�P�_
                {
                    maxa=max(maxa,min(height[i],height[j-1])*abs(j-1-i));//�ʺA�W��
                    //���N�W�@�������G�s�_�өM�o�@���n���檺���n������A�ݬݭ��Ӹ��j�N�s���Ӿ��u�A�@����U�h��s�̤j��
                    //�o�N�O�ʺA�W�����֤�RRRRRRRRRRRRRRR
                    j--;
                }
                else//�p�G����j��k��A�N�N���䲾�L�Ӭݦ��S���󰪪����ݡA�A�N�̤j�����n��s�P�_
                {
                    maxa=max(maxa,min(height[i+1],height[j])*abs(j-1-i));
                    i++;
                }
                if(i==j)//�פ���󬰬۹J�A�N��w�g���L�@���A�A�~��U�h�u�O���ư��}�F
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
