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

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;

}

void init()
{

}
void solve()
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, t;
    cin >> T;
    vi v;
    while(T--)
    {
        cin >> t;
        v.pb(t);
    }
    int n = v.size();
    int pos0 = 0, res = 0, flg = 0, cnt = 1, see_1 = 0;
    vi v2;
    int m = n * 2;
    for(int i = 0; i < m; i++)
    {
        v2.pb(v[i % n]);
    }

    for(int i = 0; i < m; i++)
    {
        if(v2[i] == 1)
        {
            see_1 = 1;
        }
        if(v2[i] == 1 && v2[(i + 1) % n] == 1)
        {
            cnt++;
        }
        else
        {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    if(see_1)
        cout << res << '\n';
    else
        cout << 0 << '\n';

    return 0;
}
