#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

const int MAX = 1e6;

struct FT
{
    vector<int> s;

    FT(int n) : s(n) {}

    void update (int pos, int diff)
    {
        for(; pos < size(s); pos |= pos + 1)
            s[pos] += diff;
    }

    int query(int pos)
    {
        int res = 0;
        for(; pos > 0; pos &= pos -1)
            res += s[pos-1];
        return res;
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> segments(MAX+2);
    vector<vector<pii>> queries(MAX+2);

    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        segments[r].push_back(l);
    }

    for(int i = 0; i < m; i++)
    {
        int cnt; cin >> cnt;
        vector<int> x(cnt);
        for(int& y : x) cin >> y;

        queries[x[0]].emplace_back(0, i);
        queries[MAX+1].emplace_back(x[cnt-1], i);
        for(int j = 1; j < cnt; j++)
            queries[x[j]].emplace_back(x[j-1], i);
    }

    // DEBUG SEGMENTS
    // for(int i = 0; i <= 12; i++)
    // {
    //     cout << i << ": ";
    //     for(int x : segments[i])
    //         cout << x << ' ';
    //     cout << '\n';
    // }

    //DEBUG QUERIES
    // for(int i = 0; i <= 12; i++)
    // {
    //     cout << i << ": ";
    //     for(auto [l, idx] : queries[i])
    //         cout << l << ' ' << idx << '\n';
    //     cout << '\n';
    // }
    // cout << "1e6+1: ";
    // for(auto [l, idx] : queries[MAX+1])
    //     cout << l << ' ' << idx << '\n';

    vector<int> ans(m);

    FT bit(MAX+2);

    for(int r = 1; r <= MAX+1; r++)
    {
        for(auto [l, idx] : queries[r])
        {
            ans[idx] += bit.query(r+1) - bit.query(l+1);
        }

        for(int l : segments[r])
        {
            bit.update(l, 1);
        }
    }

    for(int x : ans)
    {
        cout << n - x << '\n';
    }

    return 0;
}
