#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int h, int m)
{
    int h_ones = h % 10;
    int h_tens = h / 10;
    int m_ones = m % 10;
    int m_tens = m / 10;

    int h2 = h_tens * 10 + m_tens;
    int m2 = h_ones * 10 + m_ones;

    return h2 < 24 and m2 < 60;
}

pair<int, int> next(int h, int m)
{
    m++;

    if (m == 60)
    {
        m = 0;
        h++;
    }

    if (h == 24)
    {
        h = 0;
    }

    return {h, m};
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int h, m;
    cin >> h >> m;

    while (!check(h, m))
    {
        pair<int, int> p = next(h, m);
        h = p.first;
        m = p.second;
    }

    cout << h << ' ' << m << '\n';

    return 0;
}
