#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int32_t main ()
{
    int n; cin >> n;
 
    int last; cin >> last;
    n--;
    int ans = 0;
    while (n--)
    {
        int cur; cin >> cur;
 
        if (cur < last)
        {
            ans += last - cur;
 
            cur = last;
        }
 
        last = cur;
    }
 
    cout << ans << '\n';
 
    return 0;
}
