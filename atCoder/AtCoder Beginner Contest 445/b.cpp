#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<string> str;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        str.push_back(s);
        m = max(m, (int)s.size());
    }

    for(string s : str)
    {
        int quant = (m - s.size())/2;
        for(int i = 0; i < quant; i++) cout << '.';
        cout << s;
        for(int i = 0; i < quant; i++) cout << '.';
        cout << '\n';
    }

    return 0;
}
