#include <bits/stdc++.h>
using namespace std;

int grid[3][3];

int main ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
        }
    }

    int sums[3];
    sums[0] = grid[0][1] + grid[0][2];
    sums[1] = grid[1][0] + grid[1][2];
    sums[2] = grid[2][0] + grid[2][1];

    int MIN, MINindex;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            MIN = sums[0];
            MINindex = i;

            continue;
        }

        if (sums[i] < MIN)
        {
            MIN = sums[i];
            MINindex = i;
        }
    }

    int MAX = -1, MAXindex;
    for (int i = 0; i < 3; i++)
    {
        if (sums[i] > MAX)
        {
            MAX = sums[i];
            MAXindex = i;
        }
    }

    if (MAXindex == MINindex) MINindex = (MINindex + 1) % 3;

    int MIDDLEindex = 3 - (MAXindex + MINindex);

    int toAdd[3];
    toAdd[0] = sums[0] - MIN;
    toAdd[1] = sums[1] - MIN;
    toAdd[2] = sums[2] - MIN;

    int answer = (sums[MAXindex] - (toAdd[0] + toAdd[1] + toAdd[2]));

    bool even = (answer & 1)? false : true;

    answer = answer / 2;

    if (!even) answer++;

    grid[MAXindex][MAXindex] = answer;
    grid[MINindex][MINindex] = answer + toAdd[MAXindex];
    grid[MIDDLEindex][MIDDLEindex] = answer + toAdd[MIDDLEindex];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
