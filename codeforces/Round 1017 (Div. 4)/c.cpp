#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
 
        vector<bool> seen(2*n + 1, false);
        vector<int> passcode(2*n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> passcode[i+j];
                seen[passcode[i+j]] = true;
            }
        }
 
        for (int i = 1; i <= 2*n; i++)
        {
            if (!seen[i])
                passcode[1] = i;
        }
 
        for (int i = 1; i <= 2*n; i++)
            cout << passcode[i] << " ";
        cout << endl;
    }
 
    return 0;
}
