#include <bits/stdc++.h>
using namespace std;


#define int long long


vector<int> z(string s)
{
    int n = s.size();
    vector<int> z(n);

    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(0LL, min(z[i-x], y-i+1));

        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
        {
            x = i;
            y = i+z[i];
            z[i]++;
        }
    }

    return z;
}


int32_t main ()
{
   cin.tie(0)->sync_with_stdio(0);


   int n; cin >> n;
   string t; cin >> t;


   string a = t.substr(0, n);
   string b = t.substr(n);
   reverse(b.begin(), b.end());

//    cout << a << ' ' << b << '\n';

   string x = a + "#" + b;
   vector<int> z_x = z(x);


   string y = b + "#" + a;
   vector<int> z_y = z(y);


    for (int k = 0; k < n; k++)
    {
        int i = n + 1 + k;
        int j = 2*n - k + 1;

        if ((k == 0 and z_x[i] == n) or z_x[i] + z_y[j] == n)
        {
            int ans = n - k;
            for (int i = 0; i < 2*n; i += i == ans-1 ? n+1 : 1)
                cout << t[i];
            cout << '\n' << ans << '\n';
            return 0;
        }
    }

   cout << "-1\n";

   return 0;
}
