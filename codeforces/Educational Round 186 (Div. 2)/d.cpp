#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int factorial[51];

void init()
{
    factorial[0] = 1;
    for(int i = 1; i <= 50; i++)
    {
        factorial[i] = (i * factorial[i-1]) % mod;
    }
}

int fexp(int a, int b)
{
    if(b == 0) return 1;

    int h = fexp(a, b/2);
    h = (h * h) % mod;
    if(b & 1) h = (h * a) % mod;

    return h;
}

void solve()
{
    int n; cin >> n;

    vector<int> v(n+1);
    for(int& x : v) cin >> x;

    int sum = 0;
    for(int x : v) sum += x;

    int limit = sum/n + (sum % n ? 1 : 0);
    int fixed = 0;
    for(int i = 1; i <= n; i++)
    {
        if(v[i] > limit)
        {
            cout << "0\n";
            return;
        }

        if(v[i] == limit) fixed++;
    }

    int free = n - fixed;

    int num_limit = sum % n;
    if(num_limit == 0) num_limit = n;
    int ans = (factorial[num_limit] * factorial[n - num_limit]) % mod;

    int spaces = num_limit - fixed;
    if(spaces < 0)
    {
        cout << "0\n";
        return;
    }
    int choose = (factorial[free] * fexp(factorial[spaces], mod-2)) % mod;
    choose = (choose * fexp(factorial[free - spaces], mod-2)) % mod;
    ans = (ans * choose) % mod;

    cout << ans << "\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    init();

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
