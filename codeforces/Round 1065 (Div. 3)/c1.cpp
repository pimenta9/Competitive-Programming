#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;;
    
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& y : b) cin >> y;

    int quant_1 = 0, last;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1) quant_1++;
        if (b[i] == 1) quant_1++;

        if (a[i] != b[i]) last = i & 1;
    }

    if (quant_1 % 2 == 0)
    {
        cout << "Tie\n";
    }
    else
    {
        if (last) cout << "Mai\n";
        else cout << "Ajisai\n";
    }    
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
