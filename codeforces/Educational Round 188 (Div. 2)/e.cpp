#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();

    if(n == 1)
    {
        cout << s << '\n';
        return;
    }

    vector<int> freq(10);
    for(char c : s) freq[c - '0']++;

    auto possible_sum = [&](int i, vector<int> f) -> bool
    {
        int cur_x = i;
        while(true)
        {
            if(cur_x <= 9)
            {
                if(f[cur_x] == 0) return false;
                f[cur_x]--;
                break;
            }

            int next_x = 0;
            while(cur_x)
            {
                if(f[cur_x % 10] == 0) return false;
                f[cur_x % 10]--;
                next_x += cur_x % 10;
                cur_x /= 10;
            }

            cur_x = next_x;
        }

        int sum = 0;
        for(int d = 0; d <= 9; d++)
            sum += d * f[d];
        return sum == i;
    };

    auto digit_sum = [&](int x) -> int
    {
        if (x <= 9)
        {
            freq[x]--;
            return 0;
        }

        int result = 0;
        while(x)
        {
            result += x % 10;
            freq[x % 10]--;
            x /= 10;
        }

        return result;
    };

    for(int i = 1; i <= 9 * n; i++)
    {
        if(!possible_sum(i, freq)) continue;
        string s1, s2;

        while(i)
        {
            s2 += to_string(i);
            i = digit_sum(i);
        }

        for(int d = 9; d >= 0; d--)
            while(freq[d]--) s1.push_back(d + '0');

        cout << s1 + s2 << '\n';

        break;
    }
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
