#include <bits/stdc++.h>
using namespace std;

#define int long long

void even(int n)
{
    cout << "0\n";
    return;
}

void odd (int n)
{
    cout << "1\n";
    return;
}

void solve ()
{
    int n; cin >> n;

    if(n == 2)
    {
        cout << "2\n";
        return;
    }

    if(n == 3)
    {
        cout << "3\n";
        return;
    }

    if(n == 5)
    {
        cout << "1\n";
        return;
    }

    if(n & 1) odd(n);
    else even(n);
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
