#include <bits/stdc++.h>
using namespace std;

#define int long long

int x;

int find_distance (const vector<int>& a, const int& i)
{
    if (i == x)
    {
        if (a[a.size()-1] == x)
        {
            return 0;
        }
        else
        {
            return x - a[a.size()-1];
        }
    }

    if (i == 0)
    {
        if (a[0] == 0) return 0;
        else return a[0] - 0;
    }

    int idx = lower_bound(a.begin(), a.end(), i) - a.begin();
    if (idx > a.size()-1)
    {
        return i - a[a.size()-1];
    }
    int idx2 = idx-1;
    if (idx2 < 0)
    {
        return a[0] - i;
    }
    idx = a[idx];
    idx2 = a[idx2];

    return min(i - idx2, idx - i);
}

void solve ()
{
    int n, k;
    cin >> n >> k >> x;

    vector<int> a;
    map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (seen[x]) continue;
        seen[x] = true;

        a.push_back(x);
    }

    sort(a.begin(), a.end());

    // for (int x : a) cout << x << ' ';
    // cout << '\n';

    map<int, bool> in_queue;
    priority_queue<pair<int, int>> pq;

    pq.push({find_distance(a, 0), 0});
    in_queue[0] = true;
    pq.push({find_distance(a, x), x});
    in_queue[x] = true;

    for (int i = 1; i < a.size(); i++)
    {
        int l = a[i-1], r = a[i];

        int mid = (l + r)/2;

        pq.push({min(mid-l, r-mid), mid});
        in_queue[mid] = true;
    }

    int _k = k;

    // cout << find_distance(a, 43) << '\n';

    vector<int> ans_indices;
    while (_k--)
    {
        int distance = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        // cout << distance << ' ' << idx << '\n';

        ans_indices.push_back(idx);

        if (idx-1 >= 0 and !in_queue[idx-1])
        {
            pq.push({find_distance(a, idx-1), idx-1});
            in_queue[idx-1] = true;
        }

        if (idx+1 <= x and !in_queue[idx+1])
        {
            pq.push({find_distance(a, idx+1), idx+1});
            in_queue[idx+1] = true;
        }
    }

    for (int x : ans_indices) cout << x << ' ';
    cout << '\n';

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}
