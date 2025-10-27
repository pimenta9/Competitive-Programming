#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maximum_value = 2'000'000'000;

int f(int x, int y)
{
    int _y = y;
    int d = 0;
    while (_y > 0)
    {
        d++;
        _y /= 10;
    }

    for (int i = 0; i < d; i++) x *= 10;
    return x += y;
}

int gen_power (int x)
{
    int i = 1;
    while (x > 0)
    {
        x/=10;
        i*=10;
    }
    return i;
}

int calc (int left, int right)
{
    // cout << "left: " << left << " right: " << right << '\n';
    int l = 1, r = min(right, maximum_value);

    int a, b;

    while (l <= r)
    {
        int mid = (l + r)/2;

        int square = mid*mid;

        if (square >= left)
        {
            r = mid-1;
        }
        else
        {
            a = mid;
            l = mid+1;
        }
    }

    l = 1, r = min(right, maximum_value);

    while (l <= r)
    {
        int mid = (l + r)/2;

        int square = mid*mid;

        if (square <= right)
        {
            l = mid+1;
        }
        else
        {
            b = mid;
            r = mid-1;
        }
    }

    // cout << "a: " << a << " b: " << b << '\n';
    return b - a - 1;
}

void solve ()
{
    int c, d;
    cin >> c >> d;

    int first = f(c, c + 1);
    int last = f(c, c + d);

    int power = gen_power(c + 1);
    int extreme_right = f(c, power-1);
    int left = first, right = min(last, extreme_right);
    
    int ans = 0;
    bool last_iter = false;
    while (true)
    {
        if (last <= right) last_iter = true;

        ans += calc(left, right);

        left = f(c, power);
        power *= 10;
        extreme_right = f(c, power-1);
        right = min(last, extreme_right);

        if (last_iter) break;
    }
    
    cout << ans << '\n';
    // cout << "-------------\n";
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}
