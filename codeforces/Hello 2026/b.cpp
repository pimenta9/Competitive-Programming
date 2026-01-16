#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    map<int, int> freq;
    for(int& x : v)
    {
        cin >> x;
        freq[x]++;
    }

    int ans = k-1;

    for(int i = 0; i < k-1; i++)
    {
        if(freq[i] == 0)
        {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
