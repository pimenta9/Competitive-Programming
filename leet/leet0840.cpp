// ACCEPTED!

bool check(int x, int y, vector<vector<int>>& grid)
{
    map<int, bool> m;
    for (int i = x; i < x+3; i++)
    {
        for (int j = y; j < y+3; j++)
        {
            if (m[grid[i][j]])
                return false;

            m[grid[i][j]] = true;
        }
    }

    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        int value = grid[x][y + j];

        if (value < 1 || value > 9)
            return false;

        sum += value;
    }

    for (int i = x; i < x+3; i++)
    {
        int aux = 0;
        for (int j = y; j < y+3; j++)
        {
            int value = grid[i][j];

            if (value < 1 || value > 9) return false;

            aux += value;
        }
        if (aux != sum) return false;
    }

    for (int j = y; j < y+3; j++)
    {
        int aux = 0;
        for (int i = x; i < x+3; i++)
        {
            int value = grid[i][j];

            if (value < 1 || value > 9) return false;

            aux += value;
        }
        if (aux != sum) return false;
    }

    int aux1 = 0, aux2 = 0;
    for (int i = 0; i < 3; i++)
    {
        int value1 = grid[x+i][y+i];
        int value2 = grid[x+i][y+2-i];

        if (value1 < 1 || value1 > 9 || value2 < 1 || value2 > 9)
            return false;

        aux1 += value1;
        aux2 += value2;
    }
    if (aux1 != sum || aux2 != sum) return false;

    return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid)
{
    int answer = 0;

    for (int j = 0; j <= ((int)grid[0].size() - 3); j++)
    {
        for (int i = 0; i <= ((int)grid.size() - 3); i++)
        {
            if (check(i, j, grid))
                answer++;
        }
    }

    return answer;
}
