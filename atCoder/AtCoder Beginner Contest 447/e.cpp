#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_M = 2e5;
int pow_2[MAX_M + 1];
const int mod = 998244353;

void init()
{
    pow_2[0] = 1;
    for(int i = 1; i <= MAX_M; i++)
        pow_2[i] = (pow_2[i-1] * 2) % mod;
}

struct DSU
{
    int n;
    int num_components;
    vector<int> parent;

    DSU (int sz)
    {
        n = sz;
        num_components = sz;
        parent.resize(sz, -1);
    }

    int find(int u)
    {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v)
    {
        u = find(u), v = find(v);
        if(u == v) return;
        parent[v] = u;
        num_components--;
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    init();

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({i+1, u, v});
    }

    sort(edges.rbegin(), edges.rend());

    DSU ds(n);

    vector<int> ans;

    for(auto [i, u, v] : edges)
    {
        if(ds.num_components > 2)
        {
            ds.unite(u, v);
            continue;
        }

        if(ds.find(u) == ds.find(v))
            ds.unite(u, v);
        else
            ans.push_back(i);
    }

    int answer = 0;
    for(int x : ans)
        answer = (answer + pow_2[x]) % mod;
    
    cout << answer << '\n';

    return 0;
}
