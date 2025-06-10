#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, bool> last;
    last[a[0]] = true;
    map<int, bool> next;
 
    int answer = 1;
    for (int i = 1; i < n; i++)
    {
        last.erase(a[i]);
 
        next[a[i]] = true;
 
        if (last.size() == 0)
        {
            answer++;
            swap(last, next);
        }
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
