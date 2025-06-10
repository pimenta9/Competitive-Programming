#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    n -= 3;
    cout << "1 3 ";
    for (int i = 0; i < n; i++)
        cout << i+4 << ' ';
    cout << "2\n";
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
