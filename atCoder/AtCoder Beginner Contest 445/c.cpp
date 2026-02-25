#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    auto find = [&](auto rc, int i) -> int
    {
        if(v[i] == i+1) return i+1;
        return v[i] = rc(rc, v[i]-1);
    };

    for(int i = 0; i < n; i++)
    {
        cout << find(find, i) << ' ';
    }

    cout << '\n';

    return 0;
}
