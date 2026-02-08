#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;

    if(s[0] == s[1] and s[1] == s[2])
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
