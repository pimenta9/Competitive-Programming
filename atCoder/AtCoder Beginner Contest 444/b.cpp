#include <bits/stdc++.h>
using namespace std;

#define int long long

int digitSum(int n)
{
    int ans = 0;
    while(n)
    {
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(digitSum(i) == k)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
