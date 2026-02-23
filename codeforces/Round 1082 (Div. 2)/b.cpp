#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    string s; cin >> s;

    deque<char> t;
    for(int i = 0; i < n; i++)
        if(i & 1) t.push_back('b');
        else t.push_back('a');

    for(int i = 0; i < n; i++)
    {
        bool choice = t.front() != t.back();

        if(!choice)
        {
            if(s[i] != t.front() and s[i] != '?')
            {
                cout << "NO\n";
                return;
            }

            t.pop_front();
            continue;
        }

        if(s[i] != '?')
        {
            if(s[i] == t.front())
                t.pop_front();
            else
                t.pop_back();
            continue;
        }

        if(s[i+1] != '?')
        {
            if(s[i+1] == t.front())
                t.pop_back();
            else
                t.pop_front();
            continue;
        }
        else
        {
            t.pop_front();
        }
    }

    cout << "YES\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
