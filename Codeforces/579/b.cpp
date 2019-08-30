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
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vi v(n * 4);
        int sz = n * 4;
        for(int i = 0; i < sz; i++)
        {
            cin >> v[i];
        }
 
        sort(v.begin(), v.end());
        map<int, int> kind;
        for(int i = 0, j = sz - 1; i < j;)
        {
            if(v[i] == v[i + 1] && v[j] == v[j - 1])
            {
                //printf("i %d j %d kind %d add1 \n", i, j, v[i] * v[j]);
                kind[v[i] * v[j]]++;
                i += 2;
                j -= 2;
            }
            else
            {
                i += 1;
                j -= 1;
            }
        }
 
        auto it = kind.begin();
        int ok = 0;
        while(it != kind.end())
        {
            //printf("kind %d has %d \n", it -> first, it -> second);
            if(kind.size() != 1)
            {
               ok = 0;
               break;
            }
            else if(it -> second >= n)
            {
                ok = 1;
                break;
            }
            it++;
        }
        if(ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
