#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;;
    
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& y : b) cin >> y;

    int k = 0;
    for (k = 1; k < 1'000'000; k *= 2)
    {}

    auto solve = [&](const int mask)
    {
        int last, quant = 0;

        for (int i = 0; i < n; i++)
        {
            quant += (mask & a[i]) ? 1 : 0;
            quant += (mask & b[i]) ? 1 : 0;

            if ((mask & a[i]) ^ (mask & b[i]))
                last = i;
        }

        if (quant % 2 == 0) return 0;

        if (last & 1) return 2;
        return 1;
    };

    while (k > 0)
    {
        int winner = solve(k);

        if (winner)
        {
            cout << ((winner == 1) ? "Ajisai\n" : "Mai\n");
            return;
        }

        k /= 2;
    }

    cout << "Tie\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
