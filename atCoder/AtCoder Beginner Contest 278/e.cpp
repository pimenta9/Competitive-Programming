#include <bits/stdc++.h>
using namespace std;

#define int long long

int grid[301][301];
int pfreq[301][301][301];

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int x = 1; x <= N; x++)
    {
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (grid[i][j] == x)
                    pfreq[x][i][j]++;

                pfreq[x][i][j] += pfreq[x][i-1][j];
                pfreq[x][i][j] += pfreq[x][i][j-1];
                pfreq[x][i][j] -= pfreq[x][i-1][j-1];
            }
        }
    }

    // for (int i = 1; i <= H; i++)
    // {
    //     for (int j = 1; j <= W; j++)
    //     {
    //         cout << pfreq[2][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= H - h + 1; i++)
    {
        for (int j = 1; j <= W - w + 1; j++)
        {
            int x = i + h - 1;
            int y = j + w - 1;

            int ans = 0;
            for (int z = 1; z <= N; z++)
            {
                int quant = pfreq[z][x][y];
                quant -= pfreq[z][x - h][y];
                quant -= pfreq[z][x][y - w];
                quant += pfreq[z][x - h][y - w];

                if (pfreq[z][H][W] - quant > 0)
                    ans++;
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}
