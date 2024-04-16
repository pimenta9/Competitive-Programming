#include <bits/stdc++.h>
using namespace std;

#define MAX 100

void readGrid( int n, int m, char grid[MAX][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    int n = 5;
    int m = 10;

    char grid[MAX][MAX], c = 'a';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = c;
            c++;
        }
    }

    readGrid(n, m, grid);

    return 0;
}