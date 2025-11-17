#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s; cin >> s;
    int n = s.size();
    // cout << n << '\n';

    int num_ast = 0, num_right = 0, num_left = 0, idx_ast = -1;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == '*') { num_ast++; idx_ast = i; }
        if (c == '>') num_right++;
        if (c == '<') num_left++;
    }

    if (num_ast >= 2)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == '>' and i+1 < n and (s[i+1] == '<' or s[i+1] == '*'))
        {
            cout << "-1\n";
            return;
        }

        if (c == '<' and i-1 >= 0 and (s[i-1] == '>' or s[i-1] == '*'))
        {
            cout << "-1\n";
            return;
        }
    }

    // cout << n << ' ' << idx_ast << '\n';
    if (num_ast == 1)
    {
        cout << max(n - idx_ast, idx_ast + 1) << '\n';
        return;
    }

    cout << max(num_right, num_left) << '\n';
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
