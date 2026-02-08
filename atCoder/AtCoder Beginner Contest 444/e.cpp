#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, d;
    cin >> n >> d;

    vector<int> v(n);
    for(int& x : v) cin >> x;

    map<int, int> mp1, mp2;
    mp1[v[0]]++;
    mp2[-v[0]]++;
    int l, r;
    int ans = 0;

    auto check = [&](const int idx) -> bool
    {
        if(mp1.empty()) return true;

        int x = v[idx];

        auto up = mp1.lower_bound(x);
        auto down = mp2.lower_bound(-x);

        bool b1 = up == mp1.end() or up->first >= x+d;
        bool b2 = down == mp2.end() or -down->first<= x-d;

        return b1 and b2;
    };

    for(l = 0, r = 1; l < n; )
    {
        while(r < n and check(r))
        {
            mp1[v[r]]++;
            mp2[-v[r]]++;
            r++;
        }

        // if(l == 1)
        // {
        //     cout << "map:\n";
        //     for(auto [k, v] : mp1)
        //         cout << "   " << k << ' ' << v << '\n';
        // }

        // cout << l << ' ' << r << '\n';
        ans += r - l;
        mp1[v[l]]--;
        if(mp1[v[l]] == 0)
            mp1.erase(v[l]);
        mp2[-v[l]]--;
        if(mp2[-v[l]] == 0)
            mp2.erase(-v[l]);
        l++;
    }

    cout << ans << '\n';

    return 0;
}
