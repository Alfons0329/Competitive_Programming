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

    unordered_map<char, stack<int>> m;
    unordered_map<char, stack<int>> m2;
    for(int i = 0; i < n; i++)
    {
        m[s2[i]].push(i);
    }
    
    // use s2 to match s1
    vector<pii> res;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != '?')
        {
            if(m[s1[i]].size())
            {

                int tmp = m[s1[i]].top();
                res.pb(mp(i + 1, tmp + 1));
                s2[tmp] = '!';
                m[s1[i]].pop();
            }
            else if(s2[i] == '?')
            {
                // printf("?? i + 1 %d s2i %c\n", i + 1, s2[i]);
                res.pb(mp(i + 1, i + 1));
                s2[i] = '!';
            }
            s1[i] = '!';
        }
    }

    stack<int> remain;
    for(int i = 0; i < n; i++)
    {
        if(s2[i] != '!')
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
                // printf("remain i + 1 %d, remain.top %d\n", i, remain.top());
                res.pb(mp(i + 1, remain.top() + 1));
                s1[i] = '!';
                remain.pop();
            }
        }
    }


    // use s1 to match s2
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != '!')
        {
            m2[s1[i]].push(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s2[i] != '?')
        {
            if(m2[s2[i]].size())
            {

                int tmp = m2[s2[i]].top();
                res.pb(mp(i + 1, tmp + 1));
                s1[tmp] = '!';
                m2[s2[i]].pop();
            }
            else if(s1[i] == '?')
            {
                // printf("?? i + 1 %d s2i %c\n", i + 1, s2[i]);
                res.pb(mp(i + 1, i + 1));
                s1[i] = '!';
            }
            s2[i] = '!';
        }
    }

    stack<int> remain2;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != '!')
        {
            // printf("push remain %d\n", i + 1);
            remain2.push(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s2[i] == '?')
        {
            if(remain2.size())
            {
                // printf("remain i + 1 %d, remain.top %d\n", i, remain.top());
                res.pb(mp(i + 1, remain2.top() + 1));
                remain2.pop();
            }
        }
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
