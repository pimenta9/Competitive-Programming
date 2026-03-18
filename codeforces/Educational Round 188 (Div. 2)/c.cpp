#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int A = 6*(m/a - m/lcm(a, b) - m/lcm(a, c) + m/(lcm(lcm(a, b), c)));
    A += 3*(m/lcm(a, b) - m/lcm(lcm(a, b), c));
    A += 3*(m/lcm(a, c) - m/lcm(lcm(a, b), c));
    A += 2*(m/lcm(lcm(a, b), c));

    int B = 6*(m/b - m/lcm(b, a) - m/lcm(b, c) + m/(lcm(lcm(a, b), c)));
    B += 3*(m/lcm(a, b) - m/lcm(lcm(a, b), c));
    B += 3*(m/lcm(b, c) - m/lcm(lcm(a, b), c));
    B += 2*(m/lcm(lcm(a, b), c));

    int C = 6*(m/c - m/lcm(a, c) - m/lcm(b, c) + m/(lcm(lcm(a, b), c)));
    C += 3*(m/lcm(a, c) - m/lcm(lcm(a, b), c));
    C += 3*(m/lcm(b, c) - m/lcm(lcm(a, b), c));
    C += 2*(m/lcm(lcm(a, b), c));

    cout << A << ' ' << B << ' ' << C << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
