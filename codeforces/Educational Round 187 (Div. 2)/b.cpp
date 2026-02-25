#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    sort(s.begin()+1, s.end());

    int ans1, ans2;

    int i; int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += s[i] - '0';
        if(sum >= 10) break;
    }
    ans1 = n - i;

    s[0] = '1';

    sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += s[i] - '0';
        if(sum >= 10) break;
    }
    ans2 = n - i + 1;

    cout << min(ans1, ans2) << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
