#include <stdio.h>

int grid[200][200];
int n, m;

int isThereZero(int x, int y, int s)
{
    for (int i = x; i < x + s; i++)
    {
        for (int j = y; j < y + s; j++)
        {
            if (grid[i][j] == 0)
                return 1;
        }
    }

    return 0;
}

int check(int x)
{
    for (int i = 0; i <= n - x; i++)
    {
        for (int j = 0; j <= m - x; j++)
        {
            if (!isThereZero(i, j, x))
                return 1;
        }
    }

    return 0;
}

int findLimit(int first, int last)
{
    if (last < first) return 0;

    if (first == last)
    {
        if (check(first))
            return first;

        return 0;
    }

    int middle = (first + last)/2;

    // printf("check(%d) = %d\n", middle, check(middle));
    if (check(middle))
    {
        int limit = findLimit(middle+1, last);
        
        if (limit)
            return limit;

        return middle;
    }
    else
    {
        int limit = findLimit(first, middle-1);

        if (limit)
            return limit;

        return 0;
    }
}

int min(int x, int y)
{
    if (x < y) return x;

    return y;
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int limit = findLimit(1, min(n, m));

    // printf("min = %d\nLimit = %d\n", min(n, m), limit);

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int s;
        scanf("%d", &s);

        if (s <= limit)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
