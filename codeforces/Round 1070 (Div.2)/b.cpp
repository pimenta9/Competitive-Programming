#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod (int n, int m)
{
    if (n < 0) return m - n;
    return n % m;
}

void solve ()
{
    int n; cin >> n;
    string s; cin >> s;

    int start;
    for (int i = 0; i < n; i++)
        if (s[i] == '1') start = i;

    int cur = 0, ans = 0;
    for (int i = (start + 1) % n; i != start; i = (i + 1) % n)
    {
        if (s[i] == '0')
        {
            cur++;
            if (cur > ans) ans = cur;
        }
        else
        {
            cur = 0;
        }
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
