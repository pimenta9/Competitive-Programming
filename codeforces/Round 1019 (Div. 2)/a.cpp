#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, answer;
    cin >> n;
    answer = n;
    vector<bool> seen(n+1, false);
    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
 
        if (seen[aux])
            answer--;
        else
            seen[aux] = true;
    }
    cout << answer << endl;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
