#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int r, x;
    cin >> r >> x;

    if (x == 1)
    {
        if (r >= 1600 and r <= 2999)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if (r >= 1200 and r <= 2399)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
