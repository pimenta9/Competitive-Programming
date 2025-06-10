#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    int first_1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            first_1 = i;
            break;
        }
    }
 
    int last_1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            last_1 = i;
    }
 
    if ((last_1 - first_1 + 1) > x)
        cout << "NO\n";
    else
        cout << "YES\n";
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
