#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    stack<char> s1, s2;

    int q; cin >> q;

    while (q--)
    {
        int op; cin >> op;

        if (op == 1)
        {
            char c; cin >> c;

            if (c == '(')
            {
                s1.push(c);
                s2.push(c);
            }
            else
            {
                bool complete = false;

                if (!s2.empty() and s2.top() == '(')
                {
                    complete = true;
                    s2.pop();
                }
                else
                {
                    s2.push(c);
                }

                if (complete) s1.push('a');
                else
                    s1.push(c);
            }
        }

        if (op == 2)
        {
            if (s1.top() == '(')
            {
                s2.pop();
            }
            else
            {
                if (s1.top() == 'a')
                {
                    s2.push('(');
                }
                else
                {
                    s2.pop();
                }
            }
            s1.pop();
        }

        if (s2.empty()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
