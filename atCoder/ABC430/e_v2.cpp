#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

vector<int> z(string s)
{
    int n = s.size();

    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(0LL, min(z[i-x], y-i+1));

        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
        {
            x = i;
            y = i+z[i];
            z[i]++;
        }
    }

    return z;
}


void solve ()
{
    string s; cin >> s;
    string t; cin >> t;

    int n = s.size();

    s = t + "#" + s + s;

    vector<int> z_func = z(s);

    for (int i = n+1; i < z_func.size(); i++)
    {
        if (z_func[i] == n)
        {
            cout << i - (n+1) << '\n';
            return;
        }
    }

    cout << "-1\n";
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
