#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n); for(int& x : a) cin >> x;
    int idx = 0;
    m = min(m, n - idx + 1);
    vector<int> danger(m);

    for(int t = 1; t <= l; t++)
    {
        ++*min_element(danger.begin(), danger.end());

        if(idx < n and t == a[idx])
        {
            idx++;
            danger.erase(danger.begin());
            m = min(m, n - idx + 1);
            danger.resize(m, 0);
        }
    }

    cout << danger[0] << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
