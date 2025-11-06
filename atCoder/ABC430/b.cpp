#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

vector<string> grid;

vector<string> f (int i, int j, int m)
{
    vector<string> subgrid(m);

    for (int x = i; x < i + m; x++)
    {
        for (int y = j; y < j + m; y++)
        {
            subgrid[x - i].push_back(grid[x][y]);
        }
    }

    return subgrid;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    grid.resize(n);
    map<vector<string>, int> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c; cin >> c;

            grid[i].push_back(c);
        }
    }

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            vector<string> subgrid = f(i, j, m);

            mp[subgrid]++;
        }
    }

    cout << mp.size() << '\n';

    return 0;
}
