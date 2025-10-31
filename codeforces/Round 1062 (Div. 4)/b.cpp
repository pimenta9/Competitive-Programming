#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    string s, t;
    cin >> s >> t;

    map<char, int> m1;
    for (char c : s)
    {
        m1[c]++;
    }

    map<char, int> m2;
    for (char c : t)
    {
        m2[c]++;
    }

    for (auto [k, v] : m1)
    {
        if (m2[k] != v)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}
