// ACCEPTED!

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
{
    int step[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    vector<vector<int>> answer;

    int k = 1, n = rows*cols, x = rStart, y = cStart;
    for (int i = 0; n != 0; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if ((x >= 0 && x < rows) && (y >= 0 && y < cols))
            {
                answer.push_back({x, y});
                n--;
            }

            x += step[i%4][0];
            y += step[i%4][1];
        }

        if (i%2) k++;
    }

    return answer;
}
