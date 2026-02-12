#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int n, c;
const int MAX_N = 3e3;
char grid[MAX_N][MAX_N];
int step[3] = {-1, 0, 1};

bool check(int i, int j)
{
    return i >= 0 and i < n and j >= 0 and j < n;
}

void solve ()
{
    cin >> n >> c;

    vector<int> deepest(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            if(grid[i][j] == '#')
                deepest[j] = i;
        }
    }

    vector<int> ans(n), broken(n);

    queue<pii> q;
    q.emplace(n-1, c-1);
    grid[n-1][c-1] = 'x';

    while(!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        // cout << i << ' ' << j << '\n';

        if(i == 0)
        {
            ans[j] = 1;
            continue;
        }

        for(int k = 0; k < 3; k++)
        {
            int x = i-1;
            int y = j + step[k];

            if(!check(x, y) or grid[x][y] == 'x')
                continue;

            if(grid[x][y] == '.')
            {
                q.emplace(x, y);
                grid[x][y] = 'x';
                continue;
            }

            if(deepest[y] <= x)
                broken[y] = 1;

            if(broken[y])
            {
                q.emplace(x, y);
                grid[x][y] = 'x';
            }
        }
    }

    for(int x : ans) cout << x;
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
