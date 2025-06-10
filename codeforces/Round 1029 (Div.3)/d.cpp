#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
 
    int diff = a[1] - a[2];
    if (((a[1]+diff) % (n+1)) != 0)
    {
        cout << "NO\n";
        return;
    }
    int B = (a[1] + diff)/(n+1);
    int A = B - diff;
    if (A < 0 or B < 0)
    {
        cout << "NO\n";
        return;
    }
 
    for (int i = 3; i <= n; i++)
    {
        if ((a[i] - i*A - (n-i+1)*B) != 0)
        {
            cout << "NO\n";
            return;
        }
    }
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
