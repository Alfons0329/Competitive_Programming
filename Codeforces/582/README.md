# Codeforces R582(Div 3) Report
`Blog` `Codeforces` `Report`
[Contest link](https://codeforces.com/contest/1213)

## [A - Chips Moving](https://codeforces.com/contest/1213/problem/A)
* Thought: Brure force to find each possible equalized value, and since move 2 step costs nothing, we may mod 2 and see if finally need another move of 1 step
* Analysis: 
    * Time complexoty: $O(N^2)$
    * Space complexoty: $O(N)$
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
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
```
## [C - Bad Prices](https://codeforces.com/contest/1213/problem/C)
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
```
## [D1 - Bad Prices](https://codeforces.com/contest/1213/problem/D1)
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
```

## [D2 - Bad Prices](https://codeforces.com/contest/1213/problem/D2)
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
```
## [E - Bad Prices](https://codeforces.com/contest/1213/problem/E)
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
```
## [G - Bad Prices](https://codeforces.com/contest/1213/problem/G)
* Thought:
* Analysis:
    * Time complexity;
    * Space complexity:
* Code:
```cpp
`
