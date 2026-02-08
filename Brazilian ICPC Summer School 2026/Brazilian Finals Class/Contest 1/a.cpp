#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    string s, t;
    cin >> s >> t;

    int x = 0, y = 0;

    int pow = 1;
    for(char c : s)
    {
        x += (c - '0') * pow;
        pow *= 10;
    }

    pow = 1;
    for(char c : t)
    {
        y += (c - '0') * pow;
        pow *= 10;
    }

    int z = x + y;

    string p = to_string(z);
    bool start = false;
    for(int i = p.size()-1; i >= 0; i--)
    {
        if(p[i] != '0') start = true;
        if(start)
            cout << p[i];
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
