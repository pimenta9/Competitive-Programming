#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    map<char, int> freq;
    for(char c : s) freq[c]++;
    int max_freq = -1;
    for(auto [c, f] : freq)
        if(max_freq == -1 or f > max_freq)
            max_freq = f;

    for(char c : s)
        if(freq[c] < max_freq)
            cout << c;
    cout << '\n';

    return 0;
}
