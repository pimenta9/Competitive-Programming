#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v)
    {
        cin >> x;
        x--;
    }

    for(int i = 0; i < n; i++)
    {
        int a = i;
        int b = v[a];
        int c = v[b];

        if(v[c] == a)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
