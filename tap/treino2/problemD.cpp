#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int minValue(int x, int y)
{
    if (x < y) return x;

    return y;
}

void initializeArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

bool check(int h, int w, int i, int j)
{
    return ((i >= 0 && i < h) && (j >= 0 && j < w));
}

int diagonalCheck(char grid[MAX][MAX], int h, int w, int i, int j, int addRow, int addColumn)
{
    int ans = 0;
    int x = i + addRow;
    int y = j + addColumn;
    while (check(h, w, x, y))
    {
        if (grid[x][y] == '#')
        {
            ans++;
        }
        else
            break;

        x += addRow;
        y += addColumn;
    }

    return ans;
}

int crossSize(char grid[MAX][MAX], int h, int w, int i, int j)
{
    if (grid[i][j] == '.') return 0;

    int aux;
    int min = diagonalCheck(grid, h, w, i, j, -1, -1);

    aux = diagonalCheck(grid, h, w, i, j, -1, 1);
    if (aux < min)
        min = aux;

    aux = diagonalCheck(grid, h, w, i, j, 1, -1);
    if (aux < min)
        min = aux;

    aux = diagonalCheck(grid, h, w, i, j, 1, 1);
    if (aux < min)
        min = aux;

    return min;
}

int main ()
{
    int h, w;
    cin >> h >> w;

    char grid[MAX][MAX];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    int n = minValue(h, w), aux;
    int answer[n];
    initializeArray(answer, n);
    for (int i = 1; i < (h - 1); i++)
    {
        for (int j = 1; j < (w - 1); j++)
        {

            aux = crossSize(grid, h, w, i, j);

            if (aux)
            {
                answer[aux - 1]++;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    } cout << endl;

    return 0;
}