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
        vi v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if(n == 1)
        {
            cout << "YES\n";
        }
        else
        {
            int pos = min_element(v.begin(), v.end()) - v.begin();
            // cout << "minpos " << pos << endl;
            
            int next = (pos + 1) % n;
            int prev = (pos != 0) ? (pos - 1) % n : n + (pos - 1);
            
            // cout << "prev " << prev << " next " << next << endl;
            int cnt = 1, ok = 1;
            if(v[prev] > v[next])
            {
                while(cnt < n)
                {
                    if(cnt != v[pos])
                    {
                        ok = 0;
                        break;
                    }
                    cnt++;
                    pos = (pos + 1) % n;
                    // printf("pos %d cnt %d \n", pos, cnt);
                }
            }
            else
            {
                while(cnt < n)
                {
                    if(cnt != v[pos % n])
                    {
                        ok = 0;
                        break;
                    }
                    cnt++;
                    pos = (pos != 0) ? (pos - 1) % n : n + (pos - 1);
                    // printf("pos %d cnt %d \n", pos, cnt);
                }
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
    }
    
    return 0;
}
