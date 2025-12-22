#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k & 1)
    {
        for(int i = 0; i < k; i++)
        {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    map<int, bool> tight, loose;

    vector<int> a(k);
    for(int i = 0; i < k; i++)
    {
        tight[i] = true;
    }

    int mask = (1 << (8*sizeof(n) - __builtin_clzll(n) - 1));

    while (mask > 0)
    {
        // bit = 1
        if(mask & n)
        {
            int dont_add = -1;
            if(!tight.empty())
            {
                auto [i, v] = *tight.begin();
                dont_add = i;
                loose[i] = true;
                tight.erase(i);
            }

            int kk = k-1;

            for(auto [i, v] : tight)
            {
                if(kk == 0) break;
                a[i] += mask;
                kk--;
            }

            for(auto [i, v] : loose)
            {
                if(kk == 0) break;
                if(i == dont_add) continue;

                a[i] += mask;
                kk--;
            }
        }
        else // bit = 0
        {
            int nn = loose.size() & 1 ? loose.size() - 1 : loose.size();

            for(auto [k, v] : loose)
            {
                if(nn == 0) break;

                a[k] += mask;

                nn--;
            }
        }

        mask = mask >> 1;
    }

    for(int x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
