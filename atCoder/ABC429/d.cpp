#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, c;
    cin >> n >> m >> c;

    map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;

        pos[a]++;
    }

    map<int, int> psum;
    int cur = 0;
    for (auto [k, v] : pos)
    {
        psum[k] = cur + v;
        cur = psum[k];
    }

    int _m = psum.size();
    
    map<int, int> psum2 = psum;
    for (auto [k, v] : psum)
    {
        psum2[k + m] = cur + pos[k];
        cur = psum2[k + m];
    }

    vector<pair<int, int>> psum3;
    psum3.push_back({0, 0});
    for (auto [k, v] : psum2)
        psum3.push_back({v, k});

    // cout << "_m: " << _m << '\n';
    // for (auto [x, y] : psum3) cout << x << ", " << y << '\n';

    int ans = 0, aux;
    for (int i = 1; i <= _m; i++)
    {
        // if (i != 4) continue;
        pair<int, int> p = {c + psum3[i - 1].first, -1};
        int idx = lower_bound(psum3.begin(), psum3.end(), p) - psum3.begin();

        // cout << "idx: " << idx << '\n';
        int cur_value = (psum3[idx].first - psum3[i - 1].first);
        ans += cur_value;
        // cout << "cur_value: " << cur_value << '\n';
        if (i == 1) 
        {
            aux = cur_value;
            continue;
        }

        int diff = psum3[i].second - psum3[i-1].second;
        diff--;

        ans += diff*cur_value;
    }

    // cout << "psum3[_m].second: " << psum3[_m].second << '\n';
    int diff = psum3[_m + 1].second - psum3[_m].second;
    diff--;
    // cout << "diff * aux = " << diff * aux << '\n';
    ans += diff * aux;

    cout << ans << '\n';

    return 0;
}
