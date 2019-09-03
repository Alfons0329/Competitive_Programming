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

    int n, k, ok = 0;
    cin >> n >> k;
    vi input(n);
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<vector<int> > v(n, vector<int>(0));
    vi pos_record;
    mii freq;

    // rearrange IO
    sort(input.begin(), input.end());
    for(int i = 0; i < n; i++)
    {
        int tmp = input[i];
        freq[tmp]++;
        if(freq[tmp] == k)
        {
            ok = 1;
        }
        v[i].pb(tmp);
        while(tmp)
        {
            v[i].pb(tmp / 2);
            tmp /= 2;
            freq[tmp]++;
        }
    }

    int tmp_res = 0, res = INF_INT;
    if(ok)
    {
        cout << 0;
    }
    else
    {
        auto it = freq.begin();
        while(it != freq.end()) 
        {
            tmp_res = 0;
            int cnt = 0;
            if(it -> second >= k) // if such number accumulated up to k
            {
                // brute force searching for all the possible numbers and calculate thestep
                for(int i = 0; i < n; i++)
                {
                    // accumulate the freq of same number, and add the 'step'
                    auto search = find(v[i].begin(), v[i].end(), it -> first);
                    if(search != v[i].end())
                    {
                        tmp_res += search - v[i].begin();
                        cnt++;
                    }
                    if(cnt == k)
                    {
                        break;
                    }
                }
                res = min(res, tmp_res);
            }
            it++;
        }
        cout << res;
    }

    return 0;
}
