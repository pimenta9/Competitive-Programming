// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;
    long long answer = 0, even = 0, odd = 0;

    while(n--)
    {
        int current; cin >> current;
        if(current == 1)
        {
            long long temp = odd;
            odd = even;
            even = temp;

            odd++;
        }
        else
        {
            even++;
        }

        answer += odd;
    }

    cout << answer << endl;

    return 0;
}
