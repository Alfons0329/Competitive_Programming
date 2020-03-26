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
#define wz // // cout<<"-----"<<endl;
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

const int ALPHA_SIZE = 26;
const char a = 'A';

struct node{
    node* child[ALPHA_SIZE];
    bool end;
};

node* create_node(){
    node* new_node = new node;
    new_node -> end = false;
    for(int i = 0; i < ALPHA_SIZE; i++){
        new_node -> child[i] = NULL;
    }
    return new_node;
}

void insert(node* root, string& s){
    for(char x : s){
        if(!root -> child[x - a]){
            root -> child[x - a] = create_node();
        }
        root = root -> child[x - a];
    }
    root -> end = true;
}

int search(node* root, const string& s, const string& pfx){
    int res = 0;
    int n = min(s.size(), pfx.size());
    for(int i = 0; i < n; i++){
        if(!root -> child[s[i] - a] || s[i] != pfx[i]){
            return res;
        }
        res++;
        root = root -> child[s[i] - a];
    }
    return res;
}

int group(vector<string>& g){
    node* root = create_node();
    string head = g[0]; 
    int n = g.size(), res = INT_MAX;
    insert(root, head);
    for(int i = 1; i < n; i++){
        res = min(res, search(root, head, g[i]));
    }
    return res;
}

int dp[100005][26];
void dfs(int u = 0, int idx = 0){
   for(int v = 0; v < 26; v++){
       if(dp[u][v]){
           dfs(dp[u][v], idx + 1);

       }
   } 
}

int solve(){
    int n, k;
    string s;
    cin >> n >> k;
    while(n--){
        cin >> s;
        for(char c : s){
            
        }
    }
    cout << "Case #" << cnt++ << ": " << res << '\n';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, k, cnt = 1;
    cin >> T;
    while(T--){
    }
    return 0;
}
