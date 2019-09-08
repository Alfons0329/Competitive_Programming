# Codeforces R582(Div 3) Report
`Blog` `Codeforces` `Report`
[Contest link](https://codeforces.com/contest/1213)

## [A - Chips Moving](https://codeforces.com/contest/1213/problem/A)
* Thought: Brure force to find each possible equalized value, and since move 2 step costs nothing, we may mod 2 and see if finally need another move of 1 step
* Analysis: 
    * Time complexity: $O(N^2)$
    * Space complexity: $O(N)$
* Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ull cost = INF_ULL;
    for(int i = 0; i < n; i++)
    {
        ull tmp = 0;
        for(int j = 0; j < n; j++)
        {
            if(v[i] != v[j])
            {
                int diff = abs(v[i] - v[j]);
                diff %= 2;

                if(diff)
                {
                    tmp += 1;
                }
            }
        }
        cost = min(cost, tmp);
    }
    
    cout << cost;
    return 0;
}
```
## [B - Bad Prices](https://codeforces.com/contest/1213/problem/B)
* Thought: Since in this problem we opt to compare `for each j where j > i` and check `if a[j] < a[i]`, brute force will definitely fail, thus we optimize with multiset, not only does it sort the element but also permit repeat of element. We traverse from the last element of array and see if the latter element(inserted into multiset) has smaller one)
* Analysis:
    * Time complexity: $O(NlogN)$
    * Space complexity: $O(N)$
* Code:
```cpp
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        vi v(n);
        if(n == 1)
        {
            cout << 0 << '\n';
            cin >> n; // trailing
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                cin >> v[i];
            }

            int res = 0;
            multiset<int>m;
            m.insert(v[n - 1]);
            for(int i = n - 2; i >= 0; i--)
            {
                auto lb = m.lower_bound(v[i]);
                res += (lb != m.begin());
                m.insert(v[i]);
            }
            cout << res << '\n';
            v.clear();
        }
    }

    return 0;
}
```
## [C - Book Reading](https://codeforces.com/contest/1213/problem/C)
* Thought: Use simple math to calculate the occurrance of number belogs to certain LSB.
![](https://i.imgur.com/Q8ilPUA.png)

* Analysis:
    * Time complexity: $O(n)\ \ if\ n\gt m$ else $O(1)$
    * Space complexity: $O(n)$
* Code:
```cpp
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ull T, n, m;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;

        // corner case
        if(n == m) 
        {
            cout << m % 10 << '\n';
        }
        else if(n < m)
        {
            cout << 0 << '\n';
        }
        else
        {
            // normal
            unordered_map<ull, ull> stat;
            vull v;
            ull res = 0, bs = m % 10, idx = 1;
            while(stat[bs * idx % 10] == 0 && m * idx <= n)
            {
                stat[bs * idx % 10]++;
                v.pb(m * idx);
                idx++;
            }

            ull cycle = m * (idx - 1);
            auto it = stat.begin();
            idx = 0;
            ull sz = v.size();
            while(it != stat.end() && idx < sz)
            {
                long double todo = n - v[idx], cyc = cycle; // use long double for store unsigned ll
                ull cnt = (n - v[idx]) % cycle == 0 ? (n - v[idx]) / cycle + 1 : ceil(todo / cyc);
                res += v[idx] % 10 * cnt; 
                it++;
                idx++;
            }
            cout << res << '\n';
        }
    }
    return 0;
}
```

* Here is the better solution from the official editorial of author of this problem. 
![](https://i.imgur.com/r7Dq4dk.png)
[Click](https://codeforces.com/blog/entry/69464) </br> 
and below is how it goes.
![](https://i.imgur.com/67IsdBs.png)



## [D1 - Bad Prices](https://codeforces.com/contest/1213/problem/D1)
* Thought:
* Analysis:
    * Time complexity:
    * Space complexity:
* Code:
```cpp
```

## [D2 - Bad Prices](https://codeforces.com/contest/1213/problem/D2)
* Thought:
* Analysis:
    * Time complexity:
    * Space complexity:
* Code:
```cpp
```
## [E - Bad Prices](https://codeforces.com/contest/1213/problem/E)
* Thought:
* Analysis:
    * Time complexity:
    * Space complexity:
* Code:
```cpp
```
## [G - Bad Prices](https://codeforces.com/contest/1213/problem/G)
* Thought:
* Analysis:
    * Time complexity:
    * Space complexity:
* Code:
```cpp
`
