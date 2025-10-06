#include <bits/stdc++.h>
using namespace std;
 
void solve ()
{
    long long y, x;
    cin >> y >> x;
 
    long long ans;
 
    if (x > y)
    {
        if (x % 2 != 0)
        {
            ans = x*x - y + 1;
        }
        else
        {
            ans = (x-1)*(x-1) + 1 + y - 1;
        }
    }
 
    if (y > x)
    {
        if (y % 2 == 0)
        {
            ans = y*y - x + 1;
        }
        else
        {
            ans = (y-1)*(y-1) + 1 + x - 1;
        }
    }
 
    if (x == y)
    {
        ans = x*x - x + 1;
    }
 
    cout << ans << '\n';
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
