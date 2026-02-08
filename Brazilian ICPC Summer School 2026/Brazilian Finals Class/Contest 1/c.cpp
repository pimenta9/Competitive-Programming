#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    string s; cin >> s;

    stack<pair<int, int>> stk;
    int num_open = 0;
    int ans = 0;

    for(char c : s)
    {
        if(c == '(')
        {
            stk.push({0, 0});
            num_open++;
            continue;
        }

        int quant = 0, max_h = 0, w = 0;
        while(stk.top().first != 0)
        {
            quant++;
            max_h = max(max_h, stk.top().second);
            w += stk.top().first;
            stk.pop();
        }

        num_open--;
        stk.pop();

        int width = w + quant + 1;
        int height = max_h + 1;

        // cout << width << ' ' << height << ' ';

        stk.push({width, height});

        int add = width * height;
        if(num_open & 1) add = -add;
        // cout << add << '\n';
        ans += add;
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
