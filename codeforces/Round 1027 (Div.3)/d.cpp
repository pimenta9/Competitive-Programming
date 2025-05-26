#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int, int>
 
#define MAX_n 200000
#define rightmost 0
#define leftmost 1
#define lowermost 2
#define uppermost 3
 
pii pos[MAX_n];
 
void solve()
{
    int n; cin >> n;
 
    int enemy[] = {rightmost, leftmost, lowermost, uppermost};
 
    int max_x = -1, min_x = INT_MAX;
    int max_y = -1, min_y = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
 
        if (y > max_y)
        {
            max_y = y;
            enemy[rightmost] = i;
        }
        if (y < min_y)
        {
            min_y = y;
            enemy[leftmost] = i;
        }
        if (x > max_x)
        {
            max_x = x;
            enemy[lowermost] = i;
        }
        if (x < min_x)
        {
            min_x = x;
            enemy[uppermost] = i;
        }
        pos[i] = {x, y};
    }
 
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
 
    long long answer = LONG_LONG_MAX;
    for (int k = 0; k < 4; k++)
    {
        max_x = -1, min_x = INT_MAX;
        max_y = -1, min_y = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i == enemy[k])
                continue;
 
            int x = pos[i].first;
            int y = pos[i].second;
            max_x = max(max_x, x);
            min_x = min(min_x, x);
            max_y = max(max_y, y);
            min_y = min(min_y, y);
        }
 
        long long width = max_y - min_y + 1;
        long long height = max_x - min_x + 1;
        long long area = width * height;
        if (n > area)
            area += min(width, height);
        answer = min(answer, area);
    }
    cout << answer << endl;
}
 
int main ()
{
    int t; cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}
