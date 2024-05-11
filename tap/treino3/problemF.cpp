#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int n, m, Ai, Aj, Bi, Bj;
char grid[MAX][MAX];
int dist[MAX][MAX];
int parent[MAX][MAX];

int step[2][4] = {{ 0, -1, 0, 1}, 
                  {-1,  0, 1, 0}};

bool check (int i, int j)
{
    return ((i >= 0 && i < n) && (j >= 0 && j < m));
}

void inputRead ()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
            parent[i][j] = -1;

            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                Ai = i; Aj = j;
                grid[i][j] = '#';
            }
            else if (grid[i][j] == 'B')
            {
                Bi = i; Bj = j;
                grid[i][j] = '.';
            }
        }
    }
}

bool bfs ()
{
    dist[Ai][Aj] = 0;

    queue<pair<int, int > > q;
    q.push(make_pair(Ai, Aj));

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = v.first + step[0][k];
            int y = v.second + step[1][k];

            if (check(x, y))
            {
                if (grid[x][y] == '.')
                {
                    q.push(make_pair(x, y));

                    grid[x][y] = '#';

                    dist[x][y] = dist[v.first][v.second] + 1;

                    parent[x][y] = k;
                }

                if (x == Bi && y == Bj)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

string str;
int printString ()
{
    int size = 0, x = parent[Bi][Bj], i = Bi, j = Bj;

    while (x != -1)
    {
        size++;

        switch (x)
        {
        case 0:
            str.push_back('L');
            j++;
            break;

        case 1:
            str.push_back('U');
            i++;
            break;

        case 2:
            str.push_back('R');
            j--;
            break;

        case 3:
            str.push_back('D');
            i--;
            break;
        
        default:
            break;
        }
        x = parent[i][j];
    }

    for (int i = (str.length() - 1); i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;

    return size;
}

int main ()
{
    inputRead();

    if (bfs())
    {
        cout << "YES\n";
        cout << dist[Bi][Bj] << endl;

        printString();
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
