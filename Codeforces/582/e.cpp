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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;

    int cnt = 0;
    vector<char> v(n * 3);
    for(int i = 1; i <= n * 3; i++)
    {
        v[i - 1] = cnt + 'a';
        if(i % n == 0)
        {
            cnt++;
        }
    }

    string res;
    int ok = 0;
    do 
    {
        res = "";

        for(auto x : v)
        {
            res += x;
        }

        auto found1 = res.find(s);
        auto found2 = res.find(t);

        if(found1 == string::npos && found2 == string::npos)
        {
            ok = 1;
            break;
        }
    }while(next_permutation(v.begin(), v.end()));

    if(ok)
    {
        cout << "YES\n" << res;
    }
    else
    {
        cout << "NO"; 
    }
    return 0;
}
