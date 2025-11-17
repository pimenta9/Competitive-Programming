#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (k >= n)
    {
        for (int i = 0; i < n; i++)
            cout << "0 ";
        cout << '\n';
        return 0;
    }

    for (int i = k; i < n; i++)
        cout << a[i] << ' ';
    for (int i = 0; i < k; i++)
        cout << "0 ";
    cout << '\n';

    return 0;
}
