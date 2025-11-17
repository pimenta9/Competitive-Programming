#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    map<int, map<int, bool>> m;

    while (q--)
    {
        int op; cin >> op;
        int a, b; cin >> a >> b;

        if (op == 1)
        {
            m[a][b] = true;
        }

        if (op == 2)
        {
            m[a][b] = false;
        }

        if (op == 3)
        {
            if (m[a][b] and m[b][a])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
