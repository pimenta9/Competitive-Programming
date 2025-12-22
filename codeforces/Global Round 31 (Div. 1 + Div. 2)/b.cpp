#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    vector<string> v(n);
    for(string& s : v) cin >> s;

    deque<string> dq;
    dq.push_back(v[0]);

    auto compare = [&]() -> int
    {
        int i = 0, idx_dq = 0;
        int i2 = 0, idx_dq2 = 1;

        while(idx_dq2 < size(dq))
        {
            if(dq[idx_dq][i] < dq[idx_dq2][i2])
            {
                return 0;
            }

            if(dq[idx_dq][i] > dq[idx_dq2][i2])
            {
                return 1;
            }

            i++; i2++;
            if(i == size(dq[idx_dq]))
            {
                i = 0;
                idx_dq++;
            }
            if(i2 == size(dq[idx_dq2]))
            {
                i2 = 0;
                idx_dq2++;
            }
        }

        return 0;
    };

    for(int i = 1; i < n; i++)
    {
        dq.push_back(v[i]);
        dq.push_front(v[i]);
        
        int op = compare();

        if(op == 0)
        {
            dq.pop_back();
        }

        if(op == 1)
        {
            dq.pop_front();
        }
    }

    for(string s : dq)
    {
        cout << s;
    }
    cout << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
