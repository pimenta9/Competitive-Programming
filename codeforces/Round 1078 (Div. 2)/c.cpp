#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> v(26, vector<bool>(n));

    for(int aux = 0; aux < k; aux++)
    {
        string s; cin >> s;

        for(int i = 0; i < n; i++)
        {
            v[s[i]-'a'][i] = true;
        }
    }

    for(int div = 1; div <= n; div++)
    {
        if(n % div != 0) continue;
        string ans;
        bool div_allowed = true;
        for(int resto = 0; resto < div; resto++)
        {
            bool letra_found = false;
            int letra;
            for(letra = 0; letra < 26; letra++)
            {
                bool letra_ok = true;
                int pos = resto;
                while(pos < n)
                {
                    if(!v[letra][pos])
                    {
                        letra_ok = false;
                        break;
                    }
                    pos += div;
                }
                if(letra_ok)
                {
                    letra_found = true;
                    ans.push_back(letra+'a');
                    break;
                }
            }
            if(!letra_found)
            {
                div_allowed = false;
                break;
            }
        }
        if(!div_allowed)
        {
            continue;
        }
        for(int i = 0; i < n/div; i++)
            cout << ans;
        cout << '\n';
        return;
    }
}

int32_t main ()
{
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
