// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

char grid[MAX][MAX];

int main ()
{
    int t; cin >> t;

    while (t--)
    {
        int n, k; cin >> n >> k;
        int m = n / k;

        char c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;

                if (i % k == 0 && j % k == 0)
                {
                    grid[i/k][j/k] = c;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
