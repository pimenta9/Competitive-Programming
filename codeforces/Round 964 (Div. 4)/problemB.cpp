// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t; cin >> t;

    while (t--)
    {
        int a1, a2, b1, b2, wins = 0;
        cin >> a1 >> a2 >> b1 >> b2;

        if ((a1 > b1 && a2 >= b2) || (a2 > b2 && a1 >= b1))
            wins++;

        if ((a1 > b2 && a2 >= b1) || (a2 > b1 && a1 >= b2))
            wins++;

        cout << 2*wins << endl;
    }

    return 0;
}
