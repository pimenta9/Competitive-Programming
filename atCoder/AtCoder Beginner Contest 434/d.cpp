#include <bits/stdc++.h>
using namespace std;

#define int long long

#define M 2000

int grid[M + 2][M + 2];
int psum[M + 2][M + 2];

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<array<int, 4>> clouds;

    for(int i = 0; i < n; i++)
    {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        clouds.push_back({u, d, l, r});

        grid[u][l]++;
        grid[d+1][l]--;
        grid[u][r+1]--;
        grid[d+1][r+1]++;
    }

    for(int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            grid[i][j] = grid[i - 1][j] + grid[i][j];
        }
    }

    for(int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            grid[i][j] = grid[i][j - 1] + grid[i][j];
        }
    }

    int total = 0;
    for(int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (grid[i][j] == 0)
            {
                total++;
            }
        }
    }

    for(int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
            if(grid[i][j] == 1) psum[i][j]++;
        }
    }

    for(auto[u, d, l, r] : clouds)
    {
        int sum = psum[d][r];
        sum -= psum[u-1][r];
        sum -= psum[d][l-1];
        sum += psum[u-1][l-1];

        cout << total + sum << '\n';
    }

    return 0;
}