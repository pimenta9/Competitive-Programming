#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t; cin >> t;
 
    while (t--)
    {
        string n;
        cin >> n;
 
        int i;
        for (i = n.size()-1; i >= 0; i--)
        {
            if (n[i] != '0')
                break;
        }
 
        int zeroes = 0;
        for (int j = i-1; i >= 0; i--)
        {
            if (n[i] == '0')
                zeroes++;
        }
 
        cout << n.size() - 1 - zeroes << endl;
    }
 
    return 0;
}
