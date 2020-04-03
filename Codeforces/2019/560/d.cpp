#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define fi first
#define se second
#define MEM(a,b) memset((a),(b),sizeof(a))
#define mod(x) ((x)%MOD)
#define wz cout<<"-----"<<endl;
#define pb push_back
#define mp make_pair

#define vs vector<string> 
#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull>

#define pii pair<int,int>

#define msi map<string, int>
#define mci map<char, int>
#define mii map<int, int>

#define usi unordered_map<string, int>
#define uci unordered_map<char, int>
#define uii unordered_map<int, int>

const int INF_INT = 2147483647;
const ll INF_LL = 9223372036854775807LL;
const ull INF_ULL = 18446744073709551615Ull;
const ll P = 92540646808111039LL;

const ll maxn = 1e5 + 10, MOD = 1e9 + 7;
const int Move[4][2] = {-1,0,1,0,0,1,0,-1};
const int Move_[8][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

ll div_cnt(ll n)
{
    ll res = 0;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(n / i == i)
            {
                ++res;
            }
            else
            {
                res += 2;
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, tmp;
    cin >> T;
    while(T--)
    {
        cin >> n;
        vll v;
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.pb(tmp);
        }
        sort(v.begin(), v.end());
        
        int flg = 1;
        ll res = v[0] * v.back();
        for(int i = 1; i <= n / 2; i++)
        {
            ll mul;
            if(n % 2 == 1 && i == n / 2)
            {
                mul = v[n / 2] * v[n / 2];
            }
            else
            {
                mul = v[i] * v[v.size() - i - 1];
            }
            
            if(mul != res)
            {
                cout << -1 << '\n';
                flg = 0;
                break;
            }
        }
        if(flg)
        {
            if(div_cnt(res) != n + 2)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << res << '\n';
            }
        }
    }
    
    return 0;
}
