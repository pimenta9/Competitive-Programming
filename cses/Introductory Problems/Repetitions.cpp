#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    string s;
    cin >> s;
 
    int ans = 1;
    int cur = 1;
 
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i-1])
            cur++;
        else
            cur = 1;
 
        ans = max(ans, cur);
    }
 
    cout << ans << '\n';
 
    return 0;
}
