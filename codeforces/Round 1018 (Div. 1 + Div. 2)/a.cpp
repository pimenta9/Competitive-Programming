#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    int i = 1, j = n;
    vector<int> answer(n);
    for (int k = n-2; k >= 0; k--)
    {
        if (s[k] == '>')
        {
            answer[k+1] = j;
            j--;
        }
        else if (s[k] == '<')
        {
            answer[k+1] = i;
            i++;
        }
    }
    answer[0] = i;
 
    for (int x  : answer)
        cout << x << " ";
    cout << endl;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}
