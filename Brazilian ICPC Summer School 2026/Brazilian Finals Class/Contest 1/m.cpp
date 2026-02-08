#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    map<int, int> last, ans;
    last[v[0]]++;
    ans[v[0]]++;

    for(int i = 1; i < n; i++)
    {
        map<int, int> cur;
        cur[v[i]]++;
        for(auto [g, quant] : last)
        {
            cur[gcd(g, v[i])] += quant;
        }

        for(auto [g, quant] : cur)
        {
            ans[g] += quant;
        }

        last = cur;
    }

    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;

        cout << ans[x] << '\n';
    }

    return 0;
}
