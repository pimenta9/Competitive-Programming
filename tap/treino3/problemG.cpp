#include <bits/stdc++.h>
using namespace std;

int dist[8][8];
int step[2][8] = {{-1, -2, -2,  -1, 1, 2,  2,  1}, 
                  {-2, -1,  1,   2, 2, 1, -1, -2}};

bool check (int i, int j)
{
    return ((i >= 0 && i < 8) && (j >= 0 && j < 8));
}

void distanceReset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dist[i][j] = -1;
        }
    }
}

int main ()
{
    string line;
    while (getline(cin, line))
    {
        distanceReset();

        int iFrom = line[1] - 49;
        int jFrom = line[0] - 97;

        int iTo = line[4] - 49;
        int jTo = line[3] - 97;

        dist[iFrom][jFrom] = 0;

        queue<pair<int, int> > q;
        q.push(make_pair(iFrom, jFrom));

        while (!q.empty())
        {
            pair<int, int > v = q.front();
            q.pop();

            if (v.first == iTo && v.second == jTo)
            {
                printf("To get from %c%d to %c%d takes %d knight moves.\n", jFrom + 97, iFrom + 1, jTo + 97, iTo + 1,
                                                                            dist[v.first][v.second]);
                break;
            }

            for (int k = 0; k < 8; k++)
            {
                int x = v.first + step[0][k];
                int y = v.second + step[1][k];

                if (check(x, y))
                {
                    if (dist[x][y] < 0)
                    {
                        dist[x][y] = dist[v.first][v.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    return 0;
}
