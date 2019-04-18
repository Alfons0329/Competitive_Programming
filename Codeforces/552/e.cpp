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
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, tmp, cnt = 0;
    vi v, v2;
    mii ith_pos;

    cin >> n >> k;
    while(n--)
    {
        cin >> tmp;
        v.pb(tmp);
        ith_pos[tmp] = cnt++;
    }
    v2 = v;
    sort(v2.begin(), v2.end(), cmp);

    int teacher = 0, taken = 0;
    n = v2.size();

    for(int i = 0; i < n; ++i)
    {
        cnt = 1;
        if(taken >= n)
        {
            break;
        }
        printf("ake vpos %d to %d \n", ith_pos[v2[i]], teacher);
        if(v[ith_pos[v2[i]]] > 0)
        {
            v[ith_pos[v2[i]]] = (teacher == 0) ? -1 : -2;
            v2.erase(find(v[ith_pos[v2[i]]]));
            ++taken;
        }
        while(cnt <= k)
        {
            if(v[(ith_pos[v2[i]] + cnt) % n] >  0)
            {
                printf("make vpos %d v %d to %d \n", (ith_pos[v2[i]] + cnt) % n, v[(ith_pos[v2[i]] + cnt) % n], teacher);
                v[ith_pos[v2[i]] + cnt] = (teacher == 0) ? -1 : -2;
                ++taken;
            }

            if(ith_pos[v2[i]] - cnt >= 0 && v[ith_pos[v2[i]] - cnt] >  0)
            {
                printf("Make vpos %d v %d to %d \n", ith_pos[v2[i]] - cnt, v[ith_pos[v2[i]] - cnt], teacher);
                v2.erase(find(v[ith_pos[v2[i]] - cnt]));
                v[ith_pos[v2[i]] - cnt] = (teacher == 0) ? -1 : -2;
                ++taken;
            }
            ++cnt;
        }
        teacher ^= 1;
        printf("change teacher\n");
    }

    wz;
    for(auto i : v)
    {
        cout << abs(i) << ' ';
    }
    return 0;
}
