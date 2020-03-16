#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int segment_tree[2 * MAX_N];

// build segment tree
// input arguments
// arr: array for range sum query
// n: range sum query array size
// printf is used for debugging
int build(int* arr, int n){

    // build the leaf nodes
    for(int i = 0; i < n; i++){
        segment_tree[n + i] = arr[i];
    }

    // update the corresponding parents
    for(int i = n - 1; i > 0; i--){
        segment_tree[i] = segment_tree[i << 1] + segment_tree[(i << 1) | 1];
        printf("%d, child %d + %d, ", i, i << 1, (i << 1) | 1);
        printf("%d = %d + %d \n", segment_tree[i], segment_tree[i << 1], segment_tree[(i << 1) | 1]);
    }
}

// update segment tree
// input arguments
// p: position [0, n) to update
// v: new_value
// n: original array size
// printf is used for debugging
int update(int p, int v, int n){
    segment_tree[n + p] = v;
    p += n;
    p >>= 1;

    // update its path like heapify
    for(; p > 0; p >>= 1){
        segment_tree[p] = segment_tree[p << 1] + segment_tree[(p << 1) | 1];
        printf("%d = %d + %d \n", segment_tree[p], segment_tree[p << 1], segment_tree[(p << 1) + 1]);
    }
}

// query segment tree in interval [start, end)
// input arguments
// start: interval start
// end:
int query(int start, int end, int n){
    int res = 0, l = start, r = end;
    l += n;
    r += n;
    for(; l < r ; l >>= 1, r >>= 1){
        if(l & 1){
            res += segment_tree[l++];
        }
        if(r & 1){
            res += segment_tree[--r];
        }
    }
    return res;
}

int dbg_check(int n){
    cout << "segment tree: ";
    for(int i = 1; i < 2 * n; i++){
        if((i & (i - 1)) == 0){
            cout << '\n';
        }
        cout << segment_tree[i] << ' ';
    }
    cout << '\n';
}

// main driver function
int main(){
    memset(segment_tree, 0, sizeof(segment_tree));

    int n;
    cin >> n;

    cout << "array of size " << n << '\n';
    int* arr = new int(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    build(arr, n);
    cout << "build tree done" << '\n';
    dbg_check(n);

    while(1){
        cout << "update at p, v: ";
        int p, v;
        cin >> p >> v;
        update(p, v, n);
        cout << "update tree done" << '\n';
        dbg_check(n);

        int start, end;
        cin >> start >> end;
        cout << "range sum query in [start, end)";
        cout << query(start, end, n) << '\n';
    }

    delete(arr);
    return 0;
}
