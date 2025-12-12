#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int N = 2e5;

int logv[N+1];
void make_log() {
    logv[1] = 0;
    for (int i = 2; i <= N; i++)
        logv[i] = logv[i/2] + 1;
}
struct Sparse {
    int n;
    vector<vector<int>> st;

    Sparse(vector<int>& v) {
        n = v.size();
        int k = logv[n];
        st.assign(n+1, vector<int>(k+1, 0));

        for (int i=0;i<n;i++) {
            st[i][0] = v[i];
        }

        for(int j = 1; j <= k; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int f(int a, int b) {
        return max(a, b);
    }

    int query(int l, int r) {
        int k = logv[r-l+1];
        return f(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    make_log();

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    vector<int> L(n), R(n);

    stack<pii> s1;
    for(int i = n-1; i >= 0; i--)
    {
        while(!s1.empty() and v[i] >= s1.top().first)
            s1.pop();

        R[i] = s1.empty() ? n : s1.top().second;

        s1.push({v[i], i});
    }

    stack<pii> s2;
    for(int i = 0; i < n; i++)
    {
        while(!s2.empty() and v[i] >= s2.top().first)
            s2.pop();

        L[i] = s2.empty() ? -1 : s2.top().second;

        s2.push({v[i], i});
    }

    Sparse st(v);

    vector<pii> w;
    for(int i = 0; i < n; i++)
    {
        w.push_back({v[i], i});
    }

    sort(w.begin(), w.end());

    vector<int> idx(n+1);
    for (int i = 0; i < n; i++) idx[v[i]] = i;

    vector<int> dp(n + 1);
    for (auto [x, i] : w)
    {
        int left_size = (i - 1) - (L[i] + 1) + 1;
        int right_size = (R[i] - 1) - (i + 1) + 1;

        if (left_size == 0 and right_size == 0)
        {
            dp[v[i]] = 0;
            continue;
        }

        if (left_size != 0 and right_size != 0)
        {
            int max_left = st.query(L[i] + 1, i - 1);
            int max_right = st.query(i + 1, R[i] - 1);

            int dp_left = dp[max_left];
            int dp_right = dp[max_right];

            int result_left = dp_left + (i - idx[max_left]);
            int result_right = dp_right + (idx[max_right] - i);
            
            dp[v[i]] = max(result_left, result_right);

            continue;
        }

        if (left_size == 0)
        {
            int max_right = st.query(i + 1, R[i] - 1);
            dp[v[i]] = dp[max_right] + (idx[max_right] - i);
        }
        else
        {
            int max_left = st.query(L[i] + 1, i - 1);
            dp[v[i]] = dp[max_left] + (i - idx[max_left]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
