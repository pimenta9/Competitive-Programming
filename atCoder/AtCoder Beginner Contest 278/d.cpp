#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    map<int, int> added;
    int assigned = 0;

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        added[i] = a;
    }

    int q; cin >> q;

    while (q--)
    {
        int op; cin >> op;

        if (op == 1)
        {
            int x; cin >> x;

            added.clear();
            assigned = x;
        }

        if (op == 2)
        {
            int i, x;
            cin >> i >> x;

            added[i] += x;
        }

        if (op == 3)
        {
            int i; cin >> i;
            cout << assigned + added[i] << '\n';
        }
    }

    return 0;
}
