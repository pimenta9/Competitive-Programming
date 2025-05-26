#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n; cin >> n;
 
    vector<int> v;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
 
        if (a != last)
        {
            v.push_back(a);
            last = a;
        }
    }
    n = v.size();
    for (int i = 0, j = 0; i < n; j++)
    {
        if (j & 1)
            v[i+j] = 0;
 
        if (!(i+j+1 < n) or ((v[i+j+1]-v[i+j]) >= 2))
        {
            i = i+j+1;
            j = -1;
        }
    }
 
    int answer = 0;
    for (auto x : v)
        if (x != 0)
            answer++;
    cout << answer << endl;
}
 
int main ()
{
    int t; cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}
