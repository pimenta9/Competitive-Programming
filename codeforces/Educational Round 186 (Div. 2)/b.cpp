#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a, b, aa, bb;
    cin >> aa >> bb;

    a = aa, b = bb;
    int A = 0, B = 0;

    for(int i = 1; a >= i; i *= 4)
    {
        a -= i;
        A++;
    }
    for(int i = 2; b >= i; i *= 4)
    {
        b -= i;
        B++;
    }

    int ans = A > B ? 2*B + 1 : 2*A;

    A = 0, B = 0;
    a = aa, b = bb;
    for(int i = 2; a >= i; i *= 4)
    {
        a -= i;
        A++;
    }
    for(int i = 1; b >= i; i *= 4)
    {
        b -= i;
        B++;
    }

    int Ans = B > A ? 2*A + 1 : 2*B;

    cout << max(ans, Ans) << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
