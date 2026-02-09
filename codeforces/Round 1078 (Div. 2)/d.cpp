#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;

    int num_1 = 0, quant_1 = 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]) num_1++;
        }
    }
    quant_1 = num_1;

    vector<int> col_quant_1(m);
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(grid[i][j])
                col_quant_1[j]++;
        }
    }

    num_1 /= 2;

    int quant_whole_cols = 0;

    int col;
    for(col = m-1; col >= 0; col--)
    {
        if(num_1 == 0 or col_quant_1[col] > num_1)
        {
            break;
        }

        num_1 -= col_quant_1[col];
    }

    cout << (quant_1/2) * ((quant_1 + 1)/2) << '\n';

    int total_rights = m;
    if(num_1 == 0)
    {
        for(int i = 0; i < col+1; i++)
        {
            cout << 'R';
            total_rights--;
        }
        for(int i = 0; i < n; i++)
            cout << "D";
        while(total_rights--)
            cout << 'R';
        cout << '\n';
        return;
    }

    int downs = 0;
    while(num_1)
    {
        if(grid[downs][col] == 1)
        {
            num_1--;
        }
        downs++;
    }

    int total_downs = n;

    for(int i = 0; i < col; i++)
    {
        cout << 'R';
        total_rights--;
    }
    for(int i = 0; i < downs; i++)
    {
        cout << 'D';
        total_downs--;
    }
    cout << 'R';
    total_rights--;
    while(total_downs--)
        cout << 'D';
    while(total_rights--)
        cout << 'R';
    cout << "\n";
}

int32_t main ()
{
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
