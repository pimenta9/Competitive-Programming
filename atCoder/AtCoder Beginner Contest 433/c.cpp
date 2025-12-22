#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int n = size(s);

    if (n == 1)
    {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == (s[i-1] + 1))
        {
            ans++;
            int l = i-2, r = i+1;

            while((l >= 0 and r < n) and (s[l + 1] == s[l] and s[r] == s[r-1]))
            {
                ans++;
                l--; r++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
