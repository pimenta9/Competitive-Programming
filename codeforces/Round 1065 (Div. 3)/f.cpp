#include <bits/stdc++.h>
using namespace std;

#define int long long

void init (vector<int> v, vector<int>& pm, vector<int>& sm)
{
    int n = size(v);

    pm[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pm[i] = min(pm[i-1], v[i]);
    }

    sm[n-1] = v[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        sm[i] = max(sm[i+1], v[i]);
    }
}

struct DSU
{
    int n;
    vector<int> parent;

    DSU (int sz)
    {
        n = sz;
        parent.resize(n + 1, -1);
    }

    int find (int u)
    {
        if (parent[u] == -1)
            return u;

        parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite (int u, int v)
    {
        u = find(u);        
        v = find(v);

        if (u == v) return false;

        parent[u] = v;

        return true;
    }
};

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int sum = 0;
    for (int i = n-1; i >= 1; i--)
    {
        sum += v[i];

        int sz = n - i;
        if (sum == (sz*(sz+1))/2)
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

    vector<int> prefix_min(n), suffix_max(n);
    init(v, prefix_min, suffix_max);

    DSU ds(n);

    for (int i = n-2; i >= 0; i--)
    {
        int sm = suffix_max[i + 1], x = v[i], pm = prefix_min[i - 1];
        if (sm > x and ds.unite(sm, x))
        {
            cout << x << ' ' << sm << '\n';
        }
        else if (i > 0 and pm < x)
        {
            cout << pm << ' ' << x << '\n';
            ds.unite(x, pm);
            if (ds.unite(pm, sm))
                cout << pm << ' ' << sm << '\n';
        }
    }
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
