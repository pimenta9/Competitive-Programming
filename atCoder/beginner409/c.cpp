#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main ()
{
    int n, l;
    cin >> n >> l;

    vector<int> circle(l, 0);
    circle[0] = 1;
    int current = 0;
    for (int i = 0; i < n-1; i++)
    {
        int d;
        cin >> d;

        int pos = (current+d)%l;
        circle[pos]++;
        current = pos;
    }
    
    if (l % 3 != 0)
    {
        cout << "0\n";
        return 0;
    }

    ull answer = 0;
    for (int i = 0; i < (l/3); i++)
    {
        ull a = circle[i];
        ull b = circle[i + l/3];
        ull c = circle[i + 2*(l/3)];

        answer += a*b*c;
    }
    cout << answer << endl;

    return 0;
}
