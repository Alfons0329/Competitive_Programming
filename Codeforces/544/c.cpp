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
#define vi vector<ull> 
#define vll vector<ll> 
#define vull vector<ull>

#define pii pair<ull,ull>

#define msi map<string, ull>
#define mci map<char, ull>
#define mii map<ull, ull>

#define usi unordered_map<string, ull>
#define uci unordered_map<char, ull>
#define uii unordered_map<ull, ull>

const ull INF_ull = 2147483647;
const ll INF_LL = 9223372036854775807LL;
const ull INF_ULL = 18446744073709551615Ull;
const ll P = 92540646808111039LL;

const ll maxn = 1e5 + 10, MOD = 1e9 + 7;
const int Move[4][2] = {-1,0,1,0,0,1,0,-1};
const int Move_[8][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, res = 0;
    vi v;
    cin >> n;
    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
    }
    n = v.size();

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        auto it = upper_bound(v.begin() + i, v.end(), v[i] + 5);
        res = max(res, (int(it - v.begin() - i)));
        // printf("i %d itval %d dist %d\n", i, *it, int(it - v.begin() - i));

    }
    cout << res;
    return 0;
}
