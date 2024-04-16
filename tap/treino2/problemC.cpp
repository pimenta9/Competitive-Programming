#include <bits/stdc++.h>
using namespace std;

int step[2][4] = {{ 0, -1, 0, 1},
                  {-1,  0, 1, 0}};

bool check (int i, int j, int n, int m)
{
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}

int main ()
{
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int aux = 0, x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                for (int k = 0; k < 4; k++)
                {
                    x = i + step[0][k];
                    y = j + step[1][k];

                    if (check(x, y, n, m))
                    {
                        if (grid[x][y] == '#')
                        {
                            aux++;
                        }
                    }
                }

                if (aux == 0)
                {
                    cout << "No\n";
                    return 0;
                }
            }
            
            aux = 0;
        }
    }

    cout << "Yes\n";

    return 0;
}