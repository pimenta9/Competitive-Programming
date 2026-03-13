#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();

    int a = 0, b = 0, ans = 0;
    for(char c : s)
    {
        if(c == 'A') a++;
        if(c == 'B' and a > 0) a--, b++;
        if(c == 'C' and b > 0) b--, ans++;
    }

    cout << ans << '\n';

    return 0;
}
