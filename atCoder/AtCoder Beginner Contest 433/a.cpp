#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int x, y, z;
    cin >> x >> y >> z;

    if (((x-z*y) % (z-1)) == 0 and (x-z*y)/(z-1) >= 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
