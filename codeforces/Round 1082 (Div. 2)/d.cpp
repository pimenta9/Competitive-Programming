#include <bits/stdc++.h>
using namespace std;

#define int long long

void f(int n, int k)
{
    if(n == 1)
    {
        cout << "1 1\n";
        return;
    }

    int limit = 2*n - 1;
    if(k == limit)
    {
        cout << "1 2 ";
        int a = 3, b = 1;
        while(a <= n)
            cout << a++ << ' ' << b++ << ' ';
        while(b <= n)
            cout << b++ << ' ';
        cout << '\n';
        return;
    }

    cout << n << ' ' << n << ' ';
    f(n-1, k-1);
}

void solve ()
{
    int n, k;
    cin >> n >> k;

    int limit = 2*n - 1;

    if(k < n or k > limit)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    f(n, k);
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
