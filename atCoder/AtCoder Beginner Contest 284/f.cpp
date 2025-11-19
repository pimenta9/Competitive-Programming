#include <bits/stdc++.h>
using namespace std;

#define int long long

const int p = 9973;
const int mod = 1e9 + 7;

int modulo (int n)
{
    if (n >= 0) return n % mod;

    n = abs(n);
    return mod - (n % mod);
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    string s; cin >> s;

    int pow1 = 1, pow2;
    int hash1 = 0, hash2 = 0;

    for (int i = 0; i < n; i++)
    {
        int c1 = s[i] - 'a' + 1;
        hash1 = (hash1 + c1 * pow1) % mod;

        int c2 = s[2*n-1-i] - 'a' + 1;
        hash2 = (hash2 + c2 * pow1) % mod;

        pow2 = pow1;
        pow1 = (pow1 * p) % mod;
    }

    // cout << hash1 << ' ' << hash2 << '\n';
    if (hash1 == hash2)
    {
        for (int i = 0; i < n; i++)
            cout << s[i];
        cout << '\n' << n << '\n';
        return 0;
    }

    int pow3 = 1;
    for (int i = n-1; i >= 0; i--)
    {
        int c1 = s[i] - 'a' + 1;
        int c2 = s[i + n] - 'a' + 1;

        // cout << c1 << ' ' << c2 << '\n';

        hash1 = modulo((hash1 - pow2 * c1 + pow2 * c2)*p);
        hash2 = modulo(hash2 - pow3 * c2 + pow1 * c1);

        // cout << hash1 << ' ' << hash2 << '\n';

        if (hash1 == hash2)
        {
            int ans = i;
            string str;
            for (int j = 0; j < n; j++)
                str.push_back(s[i + j]);
            for (int j = n-1; j >= 0; j--)
                cout << str[j];
            cout << '\n' << ans << '\n';
            return 0;
        }

        // pow2 = pow1;
        pow1 = (pow1 * p) % mod;
        pow3 = (pow3 * p) % mod;
    }

    cout << "-1\n";

    return 0;
}
