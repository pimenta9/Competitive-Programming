#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();
    cout << (s[0] == s[n-1] ? "Yes\n" : "No\n");

    return 0;
}
