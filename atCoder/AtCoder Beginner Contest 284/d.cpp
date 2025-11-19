#include <bits/stdc++.h>
using namespace std;

#define int long long

int find_sqrt (int n)
{
    return sqrt(n);
}

void solve()
{
    int n; cin >> n;

    int p, q;

    for (int i = 2; i*i*i <= n; i++)
    {
        if (n % i == 0)
        {
            q = i;
            p = find_sqrt(n / q);

            if (p*p == (n / q))
                break;
        }
        
        if (n % (i*i) == 0)
        {
            p = i;
            q = n / (p * p);

            break;
        }
    }

    cout << p << ' ' << q << '\n';
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
