#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int segment_tree[2 * MAX_N];

// build segment tree
// input arguments
// arr: array for range sum query
// n: range sum query array size
int build(int* arr, int n){

    // build the leaf nodes
    for(int i = 0; i < n; i++){
        segment_tree[n + i] = arr[i];
    }

    // update the corresponding parents
    for(int i = n - 1; i >= 0; i--){
        segment_tree[i] = segment_tree[i << 1] + segment_tree[(i << 1) | 1];
    }
}

// update segment tree
// input arguments
// p: position [0, n) to update
// v: new_value
// n: original array size


int update(int p, int v, int n){
    segment_tree[n + p] = v;
    p += n;
    p >>= 2;

    // update its path
    for(; p >= 1; p >>= 1){
        segment_tree[p] = segment_tree[p << 1] + segment_tree[(p << 1) | 1];
    }
}

int dbg_check(int n){
    cout << "segment tree: ";
    for(int i = 0; i < 2 * n; i++){
        if((i & (i - 1)) == 0){
            cout << '\n';
        }
        cout << segment_tree[i] << ' ';
    }
}

// main driver function
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << "array of size " << n << '\n';
    int* arr = new int(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "build tree " << '\n';
    build(arr, n);

    while(1){
        int choice;
        cin >> choice;
        if(!choice){
            break;
        }

        int p, v;
        cout << "update at p, v \n";
        if(choice == 1){
            cin >> p >> v;
            update(p, v, n);
            dbg_check(n);
        }
    }

    delete(arr);
    return 0;
}
