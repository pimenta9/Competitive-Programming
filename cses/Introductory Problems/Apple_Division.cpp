#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main ()
{
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
 
    int ans;
    for (int groups = 0; groups <= ((1 << n) - 1); groups++)
    {
        int a = 0, b = 0;
 
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & groups)
                a += p[i];
            else
                b += p[i];
        }
 
        int diff = abs(a - b);
        if (groups == 0 or diff < ans)
            ans = diff;
    }
 
    cout << ans << '\n';
 
    return 0;
}
