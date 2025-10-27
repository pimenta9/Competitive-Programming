#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    string s; cin >> s;

    map<string, int> m1;

    for (int i = 0; i <= n-k; i++)
    {
        string str;

        for (int j = 0; j < k; j++)
        {
            str.push_back(s[i + j]);
        }

        m1[str]++;
    }

    map<int, vector<string>, greater<int>> ans;
    for (auto [str, freq] : m1)
    {
        ans[freq].push_back(str);
    }

    cout << ans.begin()->first << '\n';

    for (string str : ans.begin()->second)
        cout << str << ' ';
    cout << "\n";

    return 0;
}
