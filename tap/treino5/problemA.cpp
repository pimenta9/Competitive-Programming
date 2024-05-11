#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (m[a])
        {
            cout << "NO\n";
            return 0;
        }

        m[a] = 1;
    }

    cout << "YES\n";

    return 0;
}
