#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t; cin >> t;
 
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
 
        int ones = 0, zeroes = 0;
        for (char c : s)
            if (c == '0')
                zeroes++;
            else
                ones++;
 
        if (ones < zeroes)
            swap(ones, zeroes);
 
        k -= (ones-zeroes)/2;
 
        if (k >= 0 and !(k&1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
