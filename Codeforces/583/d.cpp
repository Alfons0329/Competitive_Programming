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
bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > v(n, vector<int>(0));
    vector<int> pos_record;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v[i].pb(tmp);
        while(tmp)
        {
            v[i].pb(tmp / 2);
            tmp /= 2;
        }
        pos_record.pb(v[i].size() - 1);
    }

    int tmp_res = 0, res = INF_INT, zero_cnt = 0;

    while(zero_cnt < n)
    {
        int cnt = 0;
        tmp_res = 0;
        for(int i = 0; i < n; i++)
        {
            cnt++;
            if(cnt != k)
            {
                tmp_res += pos_record[i];
            }
            pos_record[i] -= 1;
            if(pos_record[i] == 0)
            {
                zero_cnt++;
            }
        }
        res = min(res, tmp_res);
    }
    cout << res;
    return 0;
}
