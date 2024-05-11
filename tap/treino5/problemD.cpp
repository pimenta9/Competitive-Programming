#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    map<int, int> map1;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        map1[d]++;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        if (map1[t] == 0)
        {
            cout << "NO\n";
            return 0;
        }

        map1[t]--;
    }

    cout << "YES\n";

    return 0;
}
