#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    unsigned long long answer = 0;
    vector<unsigned long long> l(n);
    vector<unsigned long long> r(n);
    vector<unsigned long long> a;
 
    for (int i = 0; i < n; i++)
        cin >> l[i];
 
    for (int i = 0; i < n; i++)
        cin >> r[i];
 
    for (int i = 0; i < n; i++)
    {
        int left, right;
        left = l[i];
        right = r[i];
 
        answer += max(left, right);
        a.push_back(-min(left, right));
    }
 
    sort(a.begin(), a.end());
 
    for (int i = 0; i < k-1; i++)
        answer += -a[i];
 
    cout << answer+1 << endl;
}
 
int main()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
