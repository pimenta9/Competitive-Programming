#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    while(n)
    {
        int next = 1;
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;

            while(!s.empty() and s.top() == next)
            {
                s.pop();
                next++;
            }

            if(x == next) next++;
            else s.push(x);
        }

        while(next <= n and !s.empty() and s.top() == next)
        {
            s.pop();
            next++;
        }

        cout << (s.empty() ? "yes\n" : "no\n");

        cin >> n;
    }

    return 0;
}
