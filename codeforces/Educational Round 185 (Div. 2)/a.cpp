#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    vector<vector<int>> grid(n+2, vector<int>(n+2));

    int cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            grid[i][j] = cnt++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int sum = grid[i][j];
            sum += grid[i + 1][j];
            sum += grid[i - 1][j];
            sum += grid[i][j + 1];
            sum += grid[i][j-1];
            ans = max(ans, sum);
        }
    }

    cout << ans << "\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
