#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t; cin >> t;
    
    while (t--)
    {
        int n; cin >> n;
        
        if (n % 2 == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    
    return 0;
}
