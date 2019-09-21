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

struct side
{
    int up;
    int down;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, x3, x4, x5, x6;
    int y1, y2, y3, y4, y5, y6;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    vector<side> xc(1e6 + 5);

    for(int i = x3; i <= x4 - 1; i++)
    {
        xc[i].up = y4 - 1;
        xc[i].down = y3;
    }
    for(int i = x5; i <= x6 - 1; i++)
    {
        xc[i].up = max(xc[i].up, y6 - 1);
        xc[i].down = min(xc[i].down, y5);
    }

    int x_flag = 0; //, y_flag = 0;
    for(int i = x1; i <= x2 - 1; i++)
    {
        // printf("i %d up %d down %d \n", i, xc[i].up, xc[i].down);
        if(!(y2 - 1 <= xc[i].up && y1 >= xc[i].down))
        {
            x_flag = 1;
            break;
        }
    }

    if(!x_flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    
    return 0;
}
