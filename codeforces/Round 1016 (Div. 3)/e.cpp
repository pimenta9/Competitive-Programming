#include <bits/stdc++.h>
using namespace std;
 
int n, k, answer;
vector<int> a;
 
bool check (int x)
{
    vector<bool> seen(x, false);
    int X = x;
    int K = k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            if (!seen[a[i]])
            {
                seen[a[i]] = true;
                X--;
            }
        }
 
        if (X == 0)
        {
            K--;
            fill(seen.begin(), seen.end(), false);
            X = x;
        }
 
        if (K == 0)
        {
            return true;
        }
    }
    return false;
}
 
int main ()
{
    a.resize(200000);
 
    int t;
    cin >> t;
 
    while (t--)
    {
        answer = 0;
        cin >> n >> k;
 
        for (int i = 0; i < n; i++)
            cin >> a[i];
 
        for (int i = 0, j = n; i <= j; )
        {
            int x = (i + j)/2;
            if (check(x))
            {
                if (x > answer) answer = x;
 
                i = x + 1;
            }
            else
                j = x - 1;
        }
 
        cout << answer << endl;
    }
 
    return 0;
}
