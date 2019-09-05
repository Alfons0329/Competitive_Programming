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
    vector<char> v(3);
    for(int i = 0; i < 3; i++)
    {
        v[i] = i + 'a';
    }


    // check 1, check the substring does not exist
    vector<string> qualified_cycle;
    string qualified_string = "";
    string res = "";
    int ok1 = 0, ok2 = 0;

    do
    {
        res.clear();
        qualified_string.clear();

        qualified_cycle.clear();
        for(auto x : v)
        {
            qualified_string += x;
        }

        if(qualified_string.find(s) == string::npos \
                && qualified_string.find(t) == string :: npos)
        {
            for(int i = 0; i < 3; i++)
            {
                qualified_cycle.pb(qualified_string);
            }
            ok1 = 1;
        }

        if(ok1 == 1)
        {
            do
            {
                for(auto x : qualified_cycle)
                {
                    res += x;
                }

                if(res.size() == 9 && res.find(s) == string::npos \
                        && res.find(t) == string :: npos)
                {
                    ok2 = 1;
                    break;
                }
            }while(next_permutation(qualified_cycle.begin(), qualified_cycle.end()));
            cout << "qs " << qualified_string << " res " << res << endl;
        }

        if(ok1 && ok2) // 2 situation satisfied
        {
            break;
        }
    }while(next_permutation(v.begin(), v.end()));

    // check 2, check the overall substring does not exist
    if(ok1 && ok2)
    {
        res.clear();
        for(int i = 0; i < n; i++)
        {
            res += qualified_cycle[0];
        }
        cout << "YES\n" << res;
    }
    else if(ok1 && !ok2)
    {
        res.clear();
        for(int i = 0, j = 0; i < 3 * n; i++)
        {
            res += qualified_string[j];
            if((i + 1) % n == 0)
            {
                j++;
            }
        }
        cout << "YES\n" << res;
    }

    return 0;
}
