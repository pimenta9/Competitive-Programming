#include <bits/stdc++.h>
using namespace std;

#define int long long

void allZeroes(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "0 ";
    }
    cout << '\n';
}

void solve ()
{
    int n; cin >> n;

    vector<int> odds, evens;

    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a & 1) odds.push_back(a);
        else evens.push_back(a);
    }

    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    vector<int> ans(n+1);

    if (odds.size() == 0)
    {
        allZeroes(n);
        return;
    }

    ans[1] = odds[0];
    int i;
    for (i = 2; i <= evens.size() + 1; i++)
    {
        ans[i] = ans[i - 1] + evens[i - 2];
    }

    for( ; i < n; i++)
    {
        ans[i] = ans[i - 2];
    }

    if (n > evens.size() + 1)
    {
        if (odds.size() & 1) ans[n] = ans[n - 2];
        else ans[n] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        cout << ans[k] << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
