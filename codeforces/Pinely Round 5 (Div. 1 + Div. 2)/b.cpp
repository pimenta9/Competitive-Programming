#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

bool check (int i, int j)
{
    return i >= 0 and i < n and j >= 0 and j < n;
}

bool check_square (vector<string> grid)
{
    bool found = false;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (grid[i][j] == '#' and grid[i+1][j] == '#' and grid[i][j+1] == '#' and grid[i+1][j+1] == '#')
            {
                grid[i][j] = 'x';
                grid[i+1][j] = 'x';
                grid[i][j+1] = 'x';
                grid[i+1][j+1] = 'x';
                found = true;
                break;
            }
        }
        if (found) break;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
            {
                return false;
            }
        }
    }

    return true;
}

bool staircase(vector<string> grid, int start_i, int start_j, int start_step, int add_i, int add_j)
{
    int step[][2] = { {add_i, 0}, {0, add_j} };

    int i = start_i;
    int j = start_j;
    int k = start_step;
    while (true)
    {
        grid[i][j] = 'x';

        int x = i + step[k][0];
        int y = j + step[k][1];

        if (!check(x, y)) break;

        i = x;
        j = y;
        k = k ^ 1;
    }

    i = start_i;
    j = start_j;
    k = start_step ^ 1;
    while (true)
    {
        grid[i][j] = 'x';

        int x = i - step[k][0];
        int y = j - step[k][1];

        if (!check(x, y)) break;

        i = x;
        j = y;
        k = k ^ 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
                return false;
        }
    }

    return true;
}

void solve ()
{
    cin >> n;

    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    int start_i, start_j;
    int num_blacks = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
            {
                num_blacks++;
                start_i = i;
                start_j = j;
            }
        }
    }

    if (num_blacks == 0)
    {
        cout << "YES\n";
        return;
    }

    if (check_square(grid))
    {
        cout << "YES\n";
        return;
    }

    bool sc1 = staircase(grid, start_i, start_j, 0, 1, 1);
    // cout << "---------\n";
    bool sc2 = staircase(grid, start_i, start_j, 1, 1, 1);
    // cout << "---------\n";
    bool sc3 = staircase(grid, start_i, start_j, 0, -1, 1);
    // cout << "---------\n";
    bool sc4 = staircase(grid, start_i, start_j, 1, -1, 1);
    // cout << "---------\n";

    if (sc1 or sc2 or sc3 or sc4)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
