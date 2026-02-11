#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int next = n, i;
    for(i = 0; i < n; i++)
    {
        if(v[i] == next)
        {
            next--;
            cout << v[i] << ' ';
        }
        else
            break;
    }

    if(i == n)
    {
        cout << '\n';
        return;
    }

    int idx_next;
    for(int j = i; j < n; j++)
    {
        if(next == v[j])
        {
            idx_next = j;
            break;
        }
    }

    for(int k = idx_next; k >= i; k--)
    {
        cout << v[k] << ' ';
    }

    for(int k = idx_next+1; k < n; k++)
        cout << v[k] << ' ';

    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
