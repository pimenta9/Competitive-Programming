#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    cout << ((n + 1) / 2 >= m ? "Yes\n" : "No\n");

    return 0;
}
