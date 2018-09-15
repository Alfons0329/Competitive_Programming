#include <bits/stdc++.h>
using namespace std;

struct ReverseInt {
    int n;
    ReverseInt(int y): n(y){}
    bool operator<(ReverseInt a)const{return n>a.n;}
};
int t[100000];

bool test(int N, int A, int dl) {
    priority_queue<ReverseInt> machines;
    for (int i = 0; i<N; i++){
        int now;
        if (i>=A){
            now = machines.top().n;
            machines.pop();
        }
        else now = 0;
        if (dl - now < t[i]) return false;
        machines.push(now + t[i]);
    }
    return true;
}

int main()
{
    int N, dl;
    cin>>N>>dl;
    bool impossible = false;
    int i;
    for (i = 0; i < N; i++){
        cin>>t[i];
        if (t[i] > dl) impossible = true;
    }
    if (impossible) {
        cout << "-1\n";
    }
    else {
        int A = 0;
        i = 1;
        while (i < N) i<<=1;
        for (i=i>>1; i > 0; i>>=1) {
            if (!test(N, A + i, dl)) A += i;
        }
        cout<<A+1<<"\n";
    }
    return 0;
}
