#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c >= a and d < b)
        cout << "Yes\n";
    else cout << "No\n";    

    return 0;
}
