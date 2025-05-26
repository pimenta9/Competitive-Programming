#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t; cin >> t;
 
    while (t--)
    {
        int s; cin >> s;
 
        int r = sqrt(s);
 
        if (r*r != s)
        {
            cout << -1 << endl;
            continue;
        }
 
        cout << r << " 0\n";
    }
 
    return 0;
}
