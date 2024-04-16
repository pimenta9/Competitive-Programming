#include <bits/stdc++.h>
using namespace std;

int minValue(int x, int y, int z)
{
    int min = x;

    if (y < min) min = y;

    if (z < min) min = z;

    return min;
}

int main ()
{
    int n;
    cin >> n;

    int v[n], prog = 0, math = 0, sports = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        switch (v[i])
        {
            case 1:
                prog++;
                break;

            case 2:
                math++;
                break;
            
            case 3:
                sports++;
                break;
            
            default:
                break;
        }
    }

    int n_teams = minValue(prog, math, sports);

    cout << n_teams << endl;

    int current = 1;

    for (int i = 0; i < n_teams; i++)
    {
        for (int j = 0; true; j++)
        {
            j = j % n;

            if (v[j] == current)
            {
                v[j] = -1;

                if (current > 1) cout << " ";

                current++;

                cout << j+1;
            }
            
            if (current > 3)
            {
                current = 1;
                cout << endl;
                break;
            }
        }
    }

    return 0;
}