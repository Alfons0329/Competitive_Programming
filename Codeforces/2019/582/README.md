# Codeforces R582(Div 3) Report
`Blog` `Codeforces` `Report`
[Contest link](https://codeforces.com/contest/1213)

Below is my self template for typing less word
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
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
```

## [A - Chips Moving](https://codeforces.com/contest/1213/problem/A)
* Thought: Brure force to find each possible equalized value, and since **move 2 step costs nothing**, we may **mod 2** and see if finally need another move of 1 step
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
* Thought: Since in this problem we decide to compare `for each j where j > i` and check `if a[j] < a[i]`. </br> Brute force will definitely fail, thus we optimize with multiset, not only does it sort the element but also permit repeat of element. </br> We traverse from the last element of array and see if the latter element(inserted into multiset) has smaller one)
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
            cin >> n; 
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
* Thought: Use simple math to calculate the occurrence of number belongs to certain LSB. Below shows how it goes.
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
                long double todo = n - v[idx], cyc = cycle; // use long double for store unsigned ll to prevent data loss
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



## [D1 - Equalizing by Division(Easy version)](https://codeforces.com/contest/1213/problem/D1)
* Thought: 
    * Step 1. Brute force, store the occurrence of each possible number including divide the number by 2
    * Step 2. Iterate through all the possible numbers(outer while loop) and input numbers(inner for loop), if its occurrence is greater than k, then we accumulate the step(where distance of such step is how much time we have to divide by 2). 
    * Step 3. Repeat until k equal numbers has been satisfied!
* Analysis:
    * Time complexity: $O(N^2\ log^2\ max(a_i))$ where $a_i$ is each input value 
        * Why? Since v is 2D array, with row N and col log(ai), so does the occurrence map, so brute force combining frequency-counting map with vector yields $(Nlog(a_i))^2$
    * Space complexity: $O(Nlog\ max(a_i))$
* Code:
```cpp
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ok = 0;
    cin >> n >> k;
    vi input(n);
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // rearrange IO
    sort(input.begin(), input.end());
    vector<vector<int> > v(n, vector<int>(0));
    mii freq;
    for(int i = 0; i < n; i++) // Step 1
    {
        int tmp = input[i];
        freq[tmp]++;
        if(freq[tmp] == k)
        {
            ok = 1;
        }
        v[i].pb(tmp);
        while(tmp)
        {
            v[i].pb(tmp / 2);
            tmp /= 2;
            freq[tmp]++;
        }
    }

    int tmp_res = 0, res = INF_INT;
    if(ok)
    {
        cout << 0;
    }
    else// Step 2
    {
        auto it = freq.begin();
        while(it != freq.end()) 
        {
            int cnt = 0;
            tmp_res = 0;
            if(it -> second >= k) 
            {
                for(int i = 0; i < n; i++)
                {
                    auto search = find(v[i].begin(), v[i].end(), it -> first);
                    if(search != v[i].end())
                    {
                        tmp_res += search - v[i].begin();
                        cnt++;
                    }
                    if(cnt == k)
                    {
                        break;
                    }
                }
                res = min(res, tmp_res);
            }
            it++;
        }
        cout << res;
    }

    return 0;
}
```

## [D2 - Bad Prices](https://codeforces.com/contest/1213/problem/D2)
* Comparison: This problem is almost the same as last one, only the input number has been increased from $50$ to $2 \times 10^5$.
* Thought: There is in fact no need to iterate the whole map and vector again. 
    * Step 1. We create a helper vector(or map) named cost for the cost of each to-be-equalized numbers  
    * Step 2. While calculating the occurrence, we may also record the corresponding cost for such number.
    * Step 3. Once the frequency of such number has been accumulated up to k , we update the result for the less cost. 
    * Step 4. Iterate again and again until all the input has been processed.
* Analysis:
    * Time complexity: $O(NlogN)$, now $max(a_i) = max(N)$ so does not matter in the log part.
    * Space complexity: $O(NlogN)$
* Code:
```cpp
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ok = 0;
    cin >> n >> k;
    vi v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int res = INT_MAX;
    mii freq; 
    mii cost; 
    for(int i = 0; i < n; i++)
    {
        int todo = v[i], power = 0;
        while(todo)
        {
            freq[todo]++;
            cost[todo] += power;
            if(freq[todo] == k)
            {
                res = min(res, cost[todo]);
            }
            todo >>= 1;
            power += 1;
        }
    }

    cout << res;
    return 0;
}
```
## [E - Two Small Strings ](https://codeforces.com/contest/1213/problem/E)
### Sorry for the quite ugly code.
* Proof that there will definitely be an answer (Or say proof of correctness) --> [here](https://codeforces.com/blog/entry/69464?#comment-539816), we can think the use of a,b,c as the **strongly connected graph** initially and gradually remove the edges from the limitation of problem.
* Thought: Use **constructive algorithm with brute force**.
    * Step 1. `qualified_string` as the string that satisfies limitation from problem, ex: `ab cb -> bca` brute force to find it $(3! = 6)$ possible (ok1)
    * Step 2. If we passed the pretest in Step 1, concatenate candidate string **2 times** to check the cycle version. </br> ex: ` bca -> bcabca` to see if matches the limitation from problem. (ok2), it is $(2! = 3)$ possible
    * Step 3. If both were satisfied, ex: `bcabca`, then  we print out the answer with the required repeating times.
    * Step 4. Otherwise, if only step 1 can be matched but not for 2, then this means pattern will be like `bbbbccccaaaa` ex: `ac ab -> bca -> bcabca still faied but bbbbccccaaaa succeeded` 
* Analysis:
    * Time complexity: $O(N)$
    * Space complexity: $O(N)$
* Code:
```cpp
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;

    int cnt = 0;
    vector<char> v(3);
    for(int i = 0; i < 3; i++)
    {
        v[i] = i + 'a';
    }

    vs qualified_cycle;
    string qualified_string = "";
    string res = "";
    int ok1 = 0, ok2 = 0;
    do // Step 1.
    {
        res.clear();
        qualified_string.clear();
        qualified_cycle.clear();

        for(auto x : v)
        {
            qualified_string += x;
        }

        if(qualified_string.find(s) == string::npos \
                && qualified_string.find(t) == string :: npos)
        {
            for(int i = 0; i < 2; i++)
            {
                qualified_cycle.pb(qualified_string);
            }
            ok1 = 1;
        }

        if(ok1 == 1)
        {
            do // Step 2.
            {
                for(auto x : qualified_cycle)
                {
                    res += x;
                }

                if(res.size() == 6 && res.find(s) == string::npos \
                        && res.find(t) == string :: npos) // cycle with abcabc
                {
                    ok2 = 1;
                    break;
                }
                else // cycle with aabbcc
                {
                    res.clear();
                    for(int i = 0, j = 0; i < 6; i++)
                    {
                        res += qualified_string[j];
                        if((i + 1) % 2 == 0)
                        {
                            j++;
                        }
                    }

                    if(res.size() == 6 && res.find(s) == string::npos \
                            && res.find(t) == string :: npos) 
                    {
                        ok2 = 2;
                        break;
                    }
                }
            }while(next_permutation(qualified_cycle.begin(), qualified_cycle.end()));
        }

        if(ok1 && ok2) // 2 situation satisfied
        {
            break;
        }
    }while(next_permutation(v.begin(), v.end()));

    if(ok1 && ok2 == 1) // abcabc type, Step 3.
    {
        res.clear();
        for(int i = 0; i < n; i++)
        {
            res += qualified_cycle[0];
        }
        cout << "YES\n" << res;
    }
    else if(ok1 && ok2 == 2) // aabbcc type, Step 4.
    {
        res.clear();
        for(int i = 0, j = 0; i < 3 * n; i++)
        {
            res += qualified_string[j];
            if((i + 1) % n == 0)
            {
                j++;
            }
        }
        cout << "YES\n" << res;
    }

    return 0;
}

```
## [G - Bad Prices](https://codeforces.com/contest/1213/problem/G)
* Thought:
* Analysis:
    * Time complexity:
    * Space complexity:
* Code:
```cpp
```
