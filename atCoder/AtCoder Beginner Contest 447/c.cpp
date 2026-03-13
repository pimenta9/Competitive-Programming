#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int ans = 0;
    int i = 0, j = 0;
    while(true)
    {
        int a1 = 0, a2 = 0;

        while(i < n and s[i] == 'A')
            a1++, i++;
        while(j < m and t[j] == 'A')
            a2++, j++;

        if((i == n and j < m) or (j == m and i < n))
        {
            cout << "-1\n";
            return 0;
        }

        if(i == n and j == m)
        {
            ans += abs(a1 - a2);
            break;
        }

        char c1 = s[i], c2 = t[j];

        if(c1 != c2)
        {
            cout << "-1\n";
            return 0;
        }

        ans += abs(a1 - a2);
        i++, j++;
    }

    cout << ans << '\n';

    return 0;
}
