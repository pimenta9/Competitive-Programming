#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    map<int, int> mp, _mp;
    int x; cin >> x;
    mp[0] = x;
    mp[x] = x;
    _mp[0] = x;
    _mp[-x] = x;

    int sum = x + x;
    cout << sum << '\n';
    
    for (int i = 1; i < n; i++)
    {
        cin >> x;

        auto it_up = mp.upper_bound(x);
        if (it_up == mp.end())
        {
            int final = -_mp.begin()->first;

            int diff = x - final;
            if (diff < mp[final])
            {
                sum -= mp[final];
                sum += 2*diff;

                mp[final] = diff;
                mp[x] = diff;
                _mp[-final] = diff;
                _mp[-x] = diff;
            }
            else
            {
                sum += diff;

                mp[x] = diff;
                _mp[-x] = diff;
            }

            cout << sum << '\n';
            continue;
        }

        int val_up = it_up->first;
        auto it_down = _mp.upper_bound(-x);
        int val_down = -(it_down->first);

        int diff_up = val_up - x;
        int diff_down = x - val_down;
        int diff = min(diff_up, diff_down);

        mp[x] = diff;
        _mp[-x] = diff;

        sum += diff;
        sum -= mp[val_up];
        sum -= mp[val_down];

        if (diff_up < mp[val_up])
        {
            mp[val_up] = diff_up;
            _mp[-val_up] = diff_up;
        }

        if (diff_down < mp[val_down])
        {
            mp[val_down] = diff_down;
            _mp[-val_down] = diff_down;
        }

        sum += mp[val_up];
        sum += mp[val_down];

        cout << sum << '\n';
    }

    return 0;
}
