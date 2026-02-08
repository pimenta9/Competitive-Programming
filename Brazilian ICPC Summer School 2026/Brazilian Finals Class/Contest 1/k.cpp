#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> a(n), d(n);
    for(int& x : a) cin >> x;
    for(int& x : d) cin >> x;

    vector<int> next(n), prev(n);
    for(int i = 0; i < n; i++)
    {
        next[i] = i+1;
        prev[i] = i-1;
    }

    map<int, bool> last;
    for(int i = 0; i < n; i++)
        last[i] = true;

    for(int k = 0; k < n; k++)
    {
        if(last.empty())
        {
            cout << "0 ";
            continue;
        }

        map<int, bool> remove;

        for(auto [i, _] : last)
        {
            int damage_taken = prev[i] >= 0 ? a[prev[i]] : 0;
            damage_taken += next[i] < n ? a[next[i]] : 0;

            if(damage_taken > d[i])
            {
                remove[i] = true;
            }
        }

        map<int, bool> cur;

        for(auto [i, _] : remove)
        {
            cur.erase(i);
            if(prev[i] >= 0)
            {
                next[prev[i]] = next[i];
                cur[prev[i]] = true;
            }
            if(next[i] < n)
            {
                prev[next[i]] = prev[i];
                cur[next[i]] = true;
            }
        }

        cout << remove.size() << ' ';

        last = cur;
    }

    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
