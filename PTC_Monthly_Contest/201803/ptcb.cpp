#include <bits/stdc++.h>
using namespace std;

vector<int>data;
vector<int>res;
vector<int>res_reverse;

struct KVPair {
    int n;
    int rank;
    bool operator<(KVPair a)const{
        return n<a.n;
    }
};

int Rnk[1000000];
int Sum[1000000];
int kinds[1000000];
#define ss(n) ((n)&-(n))
#define mod 1000000007
int sumOf(int rank) {
    int sums = 0;
    while (rank > 0) {
        sums = (sums + Sum[rank]) % mod;
        rank -= ss(rank);
    }
    return sums;
}

void addToSum(int rank, int n) {
    while (rank <= 100000) {
        Sum[rank] = (Sum[rank] + n) % mod;
        rank += ss(rank);
    }
}

int lengthOfLIS(int len) {
    map<int, int> count;
    for (int i=0;i<len;i++){
        count[data[i]] = 1;
        Sum[i+1] = 0;
    }
    std::map<int, int>::iterator it=count.begin();
    int i;
    for (i = 1; it!=count.end(); it++, i++){
        it->second = i;
    }
    for (i=0;i<len;i++){
        Rnk[i]=count[data[i]];
        int sum = (sumOf(Rnk[i]-1) + 1) % mod;
        addToSum(Rnk[i], sum);
        kinds[i] = sum-1;
        //printf("%d %d\n", Rnk[i], sum);
    }
    memset(Sum+1, 0, len*sizeof(int));
    int totle = 0;
    for (i=len-1;i>=0;i--){
        Rnk[i]=count[data[i]];
        int sum = (sumOf(Rnk[i]-1) + 1) % mod;
        addToSum(Rnk[i], sum);
        long long m = ((long long)kinds[i]) * (long long)(sum-1);
        totle = (totle + m) % mod;
        //printf("%d %d\n", Rnk[i], sum);
    }
    //puts("");
    return totle;
}

int main(int argc, char const *argv[])
{
    int tc,len;
    cin>>tc;
    while(tc--)
    {
        cin>>len;
        for(int i=0;i<len;i++)
        {
            int tmp;
            cin>>tmp;
            data.push_back(tmp);
        }
        cout<<lengthOfLIS(len)<<endl;
        data.clear();
    }
    return 0;
    return 0;
}
