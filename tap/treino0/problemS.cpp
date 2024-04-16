#include <bits/stdc++.h>
using namespace std;

#define MAX 10

bool canBeEaten(char mat[MAX][MAX], int r, int c, int i, int j)
{
    if (mat[i][j] != '.') return false;

    bool s_in_row = false, s_in_column = false;

    // same row
    for (int k = 0; k < c; k++)
    {
        if (mat[i][k] == 'S')
        {
            s_in_row = true;
        }
    }

    // same column
    for (int k = 0; k < r; k++)
    {
        if (mat[k][j] == 'S')
        {
            s_in_column = true;
        }
    }

    return !(s_in_row && s_in_column);
}

int main ()
{
    int r, c;
    cin >> r >> c;

    char mat[MAX][MAX];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (canBeEaten(mat, r, c, i, j))
            {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}