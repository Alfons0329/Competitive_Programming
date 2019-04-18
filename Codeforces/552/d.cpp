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
    int n, b, a, tmp, a_max;
    cin >> n >> b >> a;
    a_max = a;
    vi s;

    while(n--)
    {
        cin >> tmp;
        s.pb(tmp);
    }
    
    n = s.size();
    int res = 0;
    for(int i = 0; i < n; i++) // use accumulator as much as possible since it can charge
    {
        if(a == 0 && b == 0) // nothing can be used
        {
            break;
        }
        else if(s[i] == 0) // no sunlight, use what's more
        {
            if(a > 0)
            {
                a--;
                printf("0Sun use a now %d\n", a);
            }
            else if(b > 0) // if no accumulate, decrease battery
            {
                b--;
                printf("0Sun use b now %d\n", b);
            }
        }
        else if(s[i] == 1) // sunlight, use battery to let accumulator charge
        {
            if(b > 0)
            {
                b--;
                a = (a + 1) % a_max;
                printf("1Sun use b now %d\n", b);
            }
            else if(a > 0)
            {
                a--;
                printf("1Sun use a now %d\n", a);
            }

        }
        res++;
    }
    
    cout << "res:  " << res;
    return 0;
}
