#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    int minimo = 1e9+1;
    for(int& x : v)
    {
        cin >> x;
        minimo = min(minimo, x);
    }

    int aux = -1;
    for(int i = 0; i < n; i++)
    {
        if (v[i] == minimo) continue;

        if(aux == -1 or aux > v[i]-minimo)
            aux = v[i]-minimo;
    }

    int ans = max(minimo, aux);
    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
