#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    string x;

    for (int i = 0 ; i < n; i++)
    {
        cin >> x;

        if (x.length() <= 10)
        {
            cout << x << endl;
        }
        else
        {
            cout << x[0] << (x.length() - 2) << x[x.length() - 1] << endl;
        }
    }

    return 0;
}