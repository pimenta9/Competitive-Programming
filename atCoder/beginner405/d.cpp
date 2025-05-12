#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX 1000

int h, w;
char s[MAX][MAX];
int d[MAX][MAX];
int step[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
char arrow[] = {'>', 'v', '<', '^'};

bool check (int i, int j)
{
    return ((i >= 0 and i < h) and (j >= 0 and j < w));
}

void bfs (vector<pii> exits)
{
    queue<array<int, 3>> q;
    for (auto [i, j] : exits)
        q.push({i, j, 0});
    while (!q.empty())
    {
        int i = q.front()[0];
        int j = q.front()[1];
        int dist = q.front()[2];
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = i + step[k][0];
            int y = j + step[k][1];

            if (check(x, y))
            {
                if (s[x][y] != 'E' and s[x][y] != '#')
                {
                    if (d[x][y] == 0 or d[x][y] > dist+1)
                    {
                        d[x][y] = dist + 1;
                        s[x][y] = arrow[k];
                        q.push({x, y, dist + 1});
                    }
                }
            }
        }
    }
}

int main ()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> s[i][j];

    vector<pii> exits;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'E')
            {
                exits.push_back({i, j});
            }
        }
    }
    bfs(exits);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << s[i][j];
        cout << endl;
    }

    return 0;
}
