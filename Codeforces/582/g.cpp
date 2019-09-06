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

vector<int> con_nodes; // nodes for connected gtoup
vector<int> id_group; // node -> id

ll comb(int n)
{
    return n * 1LL * (n - 1) / 2;
}

int union_find(int id) // find the group for id belongs to
{
    while(id != id_group[id])
    {
       id = id_group[id]; 
    }
    return id_group[id];
}

void merge(int u, int v, ll& tmp_res)
{
    ll u_g = union_find(u);
    ll v_g = union_find(v);

    tmp_res -= comb(con_nodes[u_g]); // merge group of u and decrease its count, C(u, 2)
    tmp_res -= comb(con_nodes[v_g]); // merge group of v and decrease its count, C(v, 2)


    con_nodes[u_g] += con_nodes[v_g]; // doing merge
    tmp_res += comb(con_nodes[u_g]); // add back of C(u + v, 2)
    id_group[v_g] = id_group[u_g];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // IO
    int n, m;
    cin >> n >> m;

    vector<pii> q(m); // store queries
    vector<ll> res(m);

    // init
    con_nodes = vector<int>(n, 1); // init connected nodes with 1 for self
    id_group = vector<int>(n, 0);
    iota(id_group.begin(), id_group.end(), 0); // id -> self group
    vector<pair<int, pii> > e(n); // (weight, (u, v) edge)
    for(int i = 0; i < n - 1; i++)
    {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        e[i].second.first--; // 0-base
        e[i].second.second--;
    }

    for (int i = 0; i < m; ++i) 
    {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(e.begin(), e.end()); // sort edges based on weight
    sort(q.begin(), q.end()); // sort queries based on weight

    // solve
    
    for(int i = 0, id = 0; i < m; i++) // going through all the queries
    {
        ll tmp_res = 0;
        while(id < n && e[id].first <= q[i].first) // suitable query
        {
            int u = e[id].second.first;
            int v = e[id].second.second;

            merge(u, v, tmp_res);
            id++;
        }
        res[id] = tmp_res;
    }

    for(auto x : q)
    {
        cout << res[x.second] << ' ';
    }
    return 0;
}
