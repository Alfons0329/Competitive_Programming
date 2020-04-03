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

const ull mod =  998244353;

struct ele
{
    ll v;
    ll con; // how much contribution to the result
    ll pos;
};
bool cmp(ele a, ele b)
{
    return a.con < b.con;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll tmp;

    vector<ele> a;
    vll b;

    cin >> n;
    ele e;
    e.v = 0;
    e.pos = 0;
    a.pb(e);

    b.pb(INF_LL);

    for(int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        e.v = tmp;
        e.pos = i;
        e.con =  i * (n - i + 1ll) * tmp;
        a.pb(e);
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        b.pb(tmp);
    }

    sort(a.begin() + 1, a.end(), cmp);
    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());
    
    ll res = 0;
    for(int i = 1; i <= n; ++i)
    {
        res = res % mod + (a[i].con % mod) * (b[i] % mod) % mod;
        // printf("i %d j %d k %d ak %llu bk %llu res %llu\n", i, j, k, a_bk[k].v, b_bk[k], res);
    }

    cout << res % mod;
    return 0;
}
