#include <bits/stdc++.h>
using namespace std;
 
#define starting 0
#define ending 1
#define reward 2
#define max_day 1000000000
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
 
    int n; cin >> n;
 
    vector<array<int, 3>> projects(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
 
        projects[i] = {a, b, p};
    }
 
    sort(projects.begin(), projects.end());
 
    vector<unsigned long long> dp(n);
    dp[n-1] = projects[n-1][reward];
    for (int i = n-2; i >= 0; i--)
    {
        int a = projects[i][starting];
        int b = projects[i][ending];
        int p = projects[i][reward];
 
        unsigned long long pick = p;
        int next_possible = upper_bound(projects.begin(), projects.end(), (array<int, 3>){b, max_day+1, 0}) - projects.begin();
        pick += (next_possible < n? dp[next_possible] : 0);
        unsigned long long dont_pick = dp[i+1];
        dp[i] = max(pick, dont_pick);
    }
 
    cout << dp[0] << "\n";
 
    return 0;
}