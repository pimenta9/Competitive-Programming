#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector<pair<int, int>> operations;

    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == '0' or s[i+1] == '0') continue;

        operations.push_back({i, i+1});
        s[i] = '0';
        s[i+1] = '0';
    }

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') continue;

        if(i >= 2)
        {
            operations.push_back({i-2, i-1});
            operations.push_back({i-2, i});
            s[i] = '0'; //tem que deixar isso aqui por conta do continue
            continue;
        }

        if(s[i+2] == '1')
        {
            operations.push_back({i, i+2});
            s[i+1] = '1';
            s[i+2] = '0';
        }
        else
        {
            operations.push_back({i+1, i+2});
            operations.push_back({i, i+2});
        }

        s[i] = '0';
    }

    vector<pair<int, int>> operations2;
    for(int i = 0; i < n-1; i++)
    {
        if(t[i] == '0' or t[i+1] == '0') continue;

        operations2.push_back({i, i+1});
        t[i] = '0';
        t[i+1] = '0';
    }

    for(int i = 0; i <= n-3; i++)
    {
        if(t[i] == '0') continue;

        operations.push_back({i, i+2});
        operations.push_back({i+1, i+2});
        s[i] = '1';
    }

    if(t[n-1] == '1' or t[n-2] == '1')
    {
        int i = t[n-1] > t[n-2] ? n-1 : n-2;

        if(s[i-2] == '0')
        {
            operations.push_back({i-2, i});
            operations.push_back({i-2, i-1});
        }
        else
        {
            operations.pop_back();
            operations.pop_back();

            if(i == n-1)
            {
                operations.push_back({n-4, n-2});
                operations.push_back({n-4, n-3});
                operations.push_back({n-3, n-1});
            }
            else
            {
                operations.push_back({n-3, n-1});
                operations.push_back({n-2, n-1});
                operations.push_back({n-4, n-2});
            }
        }

        s[i] = '1';
    }

    cout << size(operations) + size(operations2) << '\n';
    for(auto [l, r] : operations) cout << l+1 << ' ' << r+1 << '\n';
    for(auto [l, r] : operations2) cout << l+1 << ' ' << r+1 << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
