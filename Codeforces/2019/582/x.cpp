#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int q;
    cin >> q;
    forn(i, q) {
        long long n, m;
        cin >> n >> m;
        n = n / m;
        vector<int> digits(10);
        forn(i, 10)
            digits[i] = ((i + 1) * m) % 10;
        long long sum = 0;
        forn(i, n % 10)
        {
            :printf("i %d di %d sum %d n %d\n", i, digits[i], sum, n);
            sum += digits[i];
        }

        cout << "sum " << sum << endl;
        cout << sum + n / 10 * accumulate(digits.begin(), digits.end(), 0LL) << endl;
        cout << "sum " << sum << endl;

    }

}
