#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    bool ans = false;
    for(int i = 0; i <= n-4; i++)
    {
        if(s[i] == '2' and s[i+1] == '0' and s[i+2] == '2' and s[i+3] == '5')
        {
            ans = true;
        }

        if(s[i] == '2' and s[i+1] == '0' and s[i+2] == '2' and s[i+3] == '6')
        {
            ans = false;
            break;
        }
    }

    if(ans) cout << "1\n";
    else cout << "0\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
