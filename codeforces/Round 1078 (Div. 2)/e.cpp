#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // caso de borda
    if(n == 1 or m == 1)
    {
        int sum = 0, greatest = a[0][0];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                greatest = max(greatest, a[i][j]);
                sum += a[i][j];
            }
        }

        cout << sum - 2*greatest << '\n';
        return;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    // dir 0 == right, dir 1 == down
    vector<vector<int>> dir(n, vector<int>(m));
    dp[n-1][m-1] = a[n-1][m-1];
    for(int i = m-2; i >= 0; i--)
    {
        dp[n-1][i] = dp[n-1][i+1] + a[n-1][i];
        dir[n-1][i] = 0;
    }
    for(int i = n-2; i >= 0; i--)
    {
        dp[i][m-1] = a[i][m-1] + dp[i+1][m-1];
        dir[i][m-1] = 1;
    }
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = m-2; j >= 0; j--)
        {
            dp[i][j] = a[i][j];
            if(dp[i+1][j] > dp[i][j+1])
            {
                dp[i][j] += dp[i+1][j];
                dir[i][j] = 1;
            }
            else
            {
                dp[i][j] += dp[i][j+1];
                dir[i][j] = 0;
            }
        }
    }
    
    vector<pair<int, int>> candidates;
    int num_non_negatives_in_path = 0;
    int i = 0, j = 0;
    while(!(i == n-1 and j == m-1))
    {
        if(a[i][j] >= 0)
        {
            num_non_negatives_in_path++;
            candidates.emplace_back(i, j);
        }
        if(dir[i][j] == 0) j++;
        else i++;
    }
    if(a[n-1][m-1] >= 0)
    {
        num_non_negatives_in_path++;
        candidates.emplace_back(n-1, m-1);
    }

    // DEBUG
    // for(auto [x, y] : candidates)
    //     cout << x << ' ' << y << '\n';
    // cout << dp[0][0] << '\n';
    //

    if(num_non_negatives_in_path == 0)
    {
        cout << dp[0][0] << '\n';
        return;
    }

    vector<vector<int>> dp2(n, vector<int>(m));
    dp2[0][0] = a[0][0];
    for(int j = 1; j < m; j++)
        dp2[0][j] = a[0][j] + dp2[0][j-1];
    for(int i = 1; i < n; i++)
        dp2[i][0] = a[i][0] + dp2[i-1][0];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp2[i][j] = a[i][j] + max(dp2[i-1][j], dp2[i][j-1]);

    // DEBUG
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout << dp2[i][j] << ' ';
    //     cout << "\n";
    // }
    // cout << '\n';
    //

    // best pleasure in a path going through (i, j)
    vector<vector<int>> best(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            best[i][j] = dp[i][j] + dp2[i][j] - a[i][j];
        }
    }

    // DEBUG
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout << best[i][j] << ' ';
    //     cout << "\n";
    // }
    // cout << '\n';
    //

    vector<vector<int>> suffix_max(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        suffix_max[i][m-1] = best[i][m-1];
    for(int i = 0; i < n; i++)
    {
        for(int j = m-2; j >= 0; j--)
        {
            suffix_max[i][j] = max(suffix_max[i][j+1], best[i][j]);
        }
    }

    vector<vector<int>> prefix_max(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        prefix_max[i][0] = best[i][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            prefix_max[i][j] = max(prefix_max[i][j-1], best[i][j]);
        }
    }

    // DEBUG
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout << prefix_max[i][j] << ' ';
    //     cout << "\n";
    // }
    // cout << '\n';
    //// DEBUG
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //         cout << suffix_max[i][j] << ' ';
    //     cout << "\n";
    // }
    // cout << '\n';
    //

    int ans;
    for(int i = 0; i < candidates.size(); i++)
    {
        int x = candidates[i].first;
        int y = candidates[i].second;

        int stay = dp[0][0] - 2*a[x][y];
        int avoid;

        if(x == 0 and y == 0)
        {
            if(i == 0 or stay < ans)
                ans = stay;
            continue;
        }

        if(x == n-1 and y == m-1)
        {
            if(i == 0 or stay < ans)
                ans = stay;
            continue;
        }

        if(x == 0)
        {
            avoid = prefix_max[1][y-1];
            int cur = max(avoid, stay);
            if(i == 0 or cur < ans)
            {
                ans = cur;
            }
            continue;
        }

        if(x == n-1)
        {
            avoid = suffix_max[n-2][y+1];
            int cur = max(avoid, stay);
            if(i == 0 or cur < ans)
            {
                ans = cur;
            }
            continue;
        }

        if(y == 0)
        {
            avoid = suffix_max[x-1][1];
            int cur = max(avoid, stay);
            if(i == 0 or cur < ans)
            {
                ans = cur;
            }
            continue;
        }

        if(y == m-1)
        {
            avoid = prefix_max[x+1][m-2];
            int cur = max(avoid, stay);
            if(i == 0 or cur < ans)
            {
                ans = cur;
            }
            continue;
        }

        avoid = max(prefix_max[x+1][y-1], suffix_max[x-1][y+1]);
        int cur = max(stay, avoid);
        if(i == 0 or cur < ans)
        {
            ans = cur;
        }
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
