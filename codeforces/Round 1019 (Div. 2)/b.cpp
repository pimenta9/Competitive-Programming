#include <bits/stdc++.h>
using namespace std;
 
vector<bool> make_reduced(string s)
{
    vector<bool> reduced;
 
    if (s[0] == '0') reduced.push_back(false);
    else
        reduced.push_back(true);
 
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i-1])
            if (s[i] == '0') reduced.push_back(false);
            else
                reduced.push_back(true);
    }
    return reduced;
}
 
vector<bool> switch_(vector<bool> reduced)
{
    if (reduced[0] == true)
    {
        if (reduced.size() > 1)
        {
            reduced[0] = false;
            reduced[1] = true;
        }
    }
 
    if (reduced.size() > 1)
    {
        if (reduced[1] == true)
        {
            if (reduced.size() > 2)
            {
                reduced[1] = false;
                reduced[2] = true;
            }
        }
    }
 
    return reduced;
}
 
void solve()
{
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    vector<bool> reduced = make_reduced(s);
    reduced = switch_(reduced);
 
    int answer = n;
    if (reduced[0] == true) answer++;
    for (int i = 1; i < reduced.size(); i++)
    {
        if (reduced[i] != reduced[i-1])
            answer++;
    }
    cout << answer << endl;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
