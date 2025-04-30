#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<map<int, bool>> a(n+1);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x, y;
            cin >> x >> y;

            a[x][y] = true;
        }
        if (op == 2)
        {
            int x; cin >> x;
            a[x][0] = true;
        }
        if (op == 3)
        {
            int x, y;
            cin >> x >> y;
            if (a[x][y] or a[x][0])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
