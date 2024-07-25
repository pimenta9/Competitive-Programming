// ACCEPTED!

#include <stdio.h>

#define MAX 100

int grid[MAX][MAX], n, x, y, answer = 0;

void readInput()
{
    scanf("%d%d%d", &n, &x, &y);

    x--;
    y--;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

int check(int i, int j)
{
    return ((i >= 0 && i < n) && (j >= 0 && j < n));
}

void dfs(int i, int j)
{
    answer++;
    int val = grid[i][j];
    grid[i][j] = 0;

    // right
    if (check(i, j+1))
    {
        if (grid[i][j+1] >= val)
        {
            dfs(i, j+1);
        }
    }
    // down
    if (check(i+1, j))
    {
        if (grid[i+1][j] >= val)
        {
            dfs(i+1, j);
        }
    }
    // left
    if (check(i, j-1))
    {
        if (grid[i][j-1] >= val)
        {
            dfs(i, j-1);
        }
    }
    // up
    if (check(i-1, j))
    {
        if (grid[i-1][j] >= val)
        {
            dfs(i-1, j);
        }
    }
}

int main ()
{
    readInput();

    dfs(x, y);

    printf("%d\n", answer);

    return 0;
}
