#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < 2*n; i++)
    {
        int x; cin >> x;
        freq[x]++;
    }

    int num_odds = 0, num_evens = 0, num_4k = 0;
    for (auto [k, v] : freq)
    {
        if (v % 4 == 0) num_4k++;
        if (v & 1) num_odds++;
        else num_evens++;
    }

    // cout << num_odds << ' ' << num_evens << ' ' << num_4k << '\n';

    int ans = num_odds;
    ans += 2*(num_evens - num_4k);
    ans += 4*(num_4k/2);
    if (num_4k & 1 and num_odds) ans += 2;

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
