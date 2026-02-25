#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int s, m;
    cin >> s >> m;

    vector<int> pot;
    for(int i = 1; m > 0; i *= 2, m /= 2)
        if(m & 1) pot.push_back(i);

    sort(pot.rbegin(), pot.rend());

    if(s % pot.back() != 0)
    {
        cout << "-1\n";
        return;
    }

    auto f = [&](int x, int s) -> bool
    {
        for(int i = 0; i < pot.size(); i++)
        {
            int quant = min(x, s/pot[i]);
            s -= quant*pot[i];
        }
        return s == 0;
    };

    int ans;
    for(int l = 1, r = s / pot.back(); l <= r; )
    {
        int x = (l + r)/2;

        if(f(x, s))
        {
            ans = x;
            r = x-1;
        }
        else
            l = x+1;
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
