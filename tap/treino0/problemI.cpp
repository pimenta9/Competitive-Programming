#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    int f, t, ans, joy;

    for (int i = 0; i < n; i++)
    {
        cin >> f >> t;

        if (t > k)
        {
            joy = f - (t - k);
        }
        else
        {
            joy = f;
        }

        if (i == 0) ans = joy;
        
        if (joy > ans) ans = joy;
    }

    cout << ans << endl;

    return 0;
}