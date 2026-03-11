#include <bits/stdc++.h>
using namespace std;

#define int long long

const int oo = 1e9;

void solve ()
{
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;

    map<int, int> freq;
    for(int x : a) freq[x]++;

    vector<int> s;
    for(int i = 0; i < n; i++)
        if(freq[i] == 0) s.push_back(i);

    vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        int prev = i == 0 ? n : a[i-1];
        int cur = a[i];

        if((cur > n or cur < n - i - 1) or (cur > prev))
        {
            cout << "NO\n";
            return;
        }

        if (cur < prev) b[i] = oo;
        else b[i] = s.back(), s.pop_back();
    }

    cout << "YES\n";
    for(int x : b) cout << x << ' ';
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
