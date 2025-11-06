#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;

    string s; cin >> s;
    bool has_b = false;
    for (char c : s) if (c == 'B') has_b = true;

    while (q--)
    {
        int a; cin >> a;

        if (!has_b)
        {
            cout << a << '\n';
            continue;
        }

        int seconds = 0;
        for (int i = 0; a > 0; i = (i + 1)%n)
        {
            seconds++;

            if (s[i] == 'A')
            {
                a -= 1;
            }
            else
            {
                a /= 2;
            }
        }

        cout << seconds << '\n';
    }
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
