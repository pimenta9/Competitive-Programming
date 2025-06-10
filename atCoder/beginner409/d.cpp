#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool operated = false;
    int l, r;
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] > s[i+1])
        {
            operated = true;
            l = i;
            for (int j = i + 2; ; j++)
            {
                if (j >= n)
                {
                    r = n-1;
                    break;
                }
                if (s[j] > s[i])
                {
                    r = j-1;
                    break;
                }
            }
            break;
        }
    }
    if (operated)
    {
        char temp = s[l];
        for (int i = l; i < r; i++)
            s[i] = s[i+1];
        s[r] = temp;
    }
    else
    {
        
    }
    cout << s << endl;
}

int main ()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
