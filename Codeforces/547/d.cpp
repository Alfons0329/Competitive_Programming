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
const int MAX_N = 2e5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    unordered_map<char, stack<int>> m; // map of alphabet position
    for(int i = 0; i < n; i++)
    {
        if(isalpha(s2[i]))
        {
            m[s2[i]].push(i);
        }
    }
    
    // match s1 s2 alphabet
    vector<pii> res;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != '?')
        {
            if(m[s1[i]].size())
            {

                int tmp = m[s1[i]].top();
                res.pb(mp(i + 1, tmp + 1));
                m[s1[i]].pop();
                s1[i] = '!';
                s2[tmp] = '!'; // use the position 
            }
        }
    }

    // match ? in s1 with s2 alphabet
    stack<int> remain; // s2 unused
    for(int i = 0; i < n; i++)
    {
        if(isalpha(s2[i]))
        {
            // printf("push remain %d\n", i + 1);
            remain.push(i);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(s1[i] == '?')
        {
            if(remain.size())
            {
                res.pb(mp(i + 1, remain.top() + 1));
                s1[i] = '!';
                s2[remain.top()] = '!';
                remain.pop();
            }
        }
    }

    // match ? in s2 with s1 alphabet
    stack<int> remain2; // s1 unused
    for(int i = 0; i < n; i++)
    {
        if(isalpha(s1[i]))
        {
            remain2.push(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s2[i] == '?')
        {
            if(remain2.size())
            {
                res.pb(mp(remain2.top() + 1, i + 1));
                s1[remain2.top()] = '!';
                s2[i] = '!';
                remain2.pop();
            }
        }
    }

    // match ? in s1 with s2 ?
    vi v1, v2;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] == '?')
        {
            v1.pb(i);
        }
        if(s2[i] == '?')
        {
            v2.pb(i);
        }
    }

    int small = min((int)v1.size(), (int)v2.size());
    for(int i = 0; i < small; i++)
    {
        res.pb(mp(v1[i] + 1, v2[i] + 1));
    }

    if(res.size())
    {
        n = res.size();
        cout << n << '\n';
        for(int i = 0; i < n; i++)
        {
            cout << res[i].first << ' ' << res[i].second << '\n';
        }
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}
