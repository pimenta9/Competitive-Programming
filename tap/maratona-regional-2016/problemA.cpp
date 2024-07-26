// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    for (int i = 0; i <= 2; i++)
    {
        int sum = a[(i+1)%3];

        if (sum == a[i])
        {
            cout << "S\n";
            return 0;
        }

        sum += a[(i+2)%3];

        if (sum == a[i])
        {
            cout << "S\n";
            return 0;
        }
    }

    cout << "N\n";

    return 0;
}
