#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int p = 135019;
const int mod = 1e9 + 9;

void solve ()
{
    string a; cin >> a;
    string b; cin >> b;

    int n; n = a.size();
    // cout << n << '\n';
    int hash1 = 0;
    int pow = 1;
    for (int i = 0; i < n; i++)
    {
        hash1 = ( hash1 + (b[i] - '0') * pow ) % mod;
        pow = (pow * p) % mod;
    }

    int hash2 = 0;
    pow = 1;
    for (int i = 0; i < n; i++)
    {
        hash2 = ( hash2 + (a[i] - '0') * pow ) % mod;
        pow = (pow * p) % mod;
    }

    if (hash1 == hash2)
    {
        cout << "0\n";
        return;
    }

    int ans = 0;
    int pow2 = 1;
    for (int i = 1; i < n; i++)
    {
        ans++;
        hash2 = ((hash2 - (a[i-1] - '0') * pow2 + (a[i-1] - '0') * pow) + mod) % mod;

        hash1 = (hash1 * p) % mod;

        pow = (pow * p) % mod;
        pow2 = (pow2 * p) % mod;

        // cout << ans << ' ' << hash1 << ' ' << hash2 << '\n';

        if (hash1 == hash2)
        {
            cout << ans << '\n';
            return;
        }
    }

    cout << "-1\n";
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
