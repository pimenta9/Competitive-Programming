#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<int> v(n);
    for(int& x : v) cin >> x;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] > v[i])
            {
                found = true;
                cout << j+1 << '\n';
                break;
            }
        }

        if (!found) cout << "-1\n";
    }

    return 0;
}
