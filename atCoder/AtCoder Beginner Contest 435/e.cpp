#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int ans = n;
    map<pii, bool> m;

    auto paint = [&](int l, int r) -> void
    {
        if (m.empty())
        {
            ans -= r - l + 1;

            m[{l, r}] = true;

            return;
        }

        int sum = 0;

        map<pii, bool>::iterator it = m.upper_bound({l, 0});
        vector<pii> to_be_erased;

        if (it != m.begin())
        {
            it--;

            if (l > it->first.second)
                it++;
            else
                l = it->first.first;
        }

        while (it != m.end() and it->first.first <= r)
        {
            r = max(r, it->first.second);

            to_be_erased.push_back(it->first);

            it++;
        }

        int blacks = 0;
        for (pii p : to_be_erased)
        {
            blacks += p.second - p.first + 1;
            m.erase(p);
        }

        ans -= (r-l+1) - blacks;

        m[{l, r}] = true;
    };

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        paint(l, r);
        cout << ans << '\n';
    }

    return 0;
}