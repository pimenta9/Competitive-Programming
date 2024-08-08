// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t; cin >> t;

    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;

        int begin, end = 0, possible = 0;
        while (n--)
        {
            cin >> begin;

            if (begin - end >= s)
            {
                possible = 1;
            }

            cin >> end;
        }
        if (m - end >= s) possible = 1;

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
