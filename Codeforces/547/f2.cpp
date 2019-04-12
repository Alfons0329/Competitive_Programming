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

bool cmp(pii p1, pii p2)
{
    return p1.second < p2.second ; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, tmp;
    vi v;
    cin >> T;
    while(T--)
    {
        cin >> tmp;
        v.pb(tmp);
    }
    int n = v.size();
    map<ll, vector<pii>> m;

    for(int i = 0; i < n; i++)
    {
        ll sum = 0, j = i;
        for(; j < n; j++)
        {
            sum += v[j];
            m[sum].push_back(mp(i, j));
        }
    }

    vector<pii>res;
    map<ll, vector<pii>>::iterator it = m.begin();
    for(; it != m.end(); it++)
    {
        sort(it -> second.begin(), it -> second.end(), cmp);
        if(it -> second.size() > res.size())
        {
            // check overlapping
            vector<bool>check(n, 0);
            vector<pii>tmp_res;
            int i = 0; // select the 1st activity
            tmp_res.pb(mp(it -> second[i].first, it -> second[i].second));
            for(int j = 1; j < it -> second.size(); j++)
            {
                if(it -> second[j].first > it -> second[i].second) // start > end of last, OK
                {
                    tmp_res.pb(mp(it -> second[j].first, it -> second[j].second));
                    i = j;
                }
            }

            if(tmp_res.size() > res.size())
            {
                res = tmp_res;
            }
        }
    }

    cout << res.size() << '\n';
    for(auto i : res)
    {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    return 0;
}
