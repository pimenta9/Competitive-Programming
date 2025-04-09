#include <bits/stdc++.h>
using namespace std;
 
bool check_prime(int x)
{
    if (x == 1) return false;
 
    for (int i = 2; i*i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
 
    return true;
}
 
int main ()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int x, k;
        cin >> x >> k;
 
        if (x == 1)
        {
            switch (k)
            {
                case 1:
                    cout << "No\n";
                    break;
                case 2:
                    cout << "Yes\n";
                    break;
                case 3:
                    cout << "No\n";
                    break;
                case 4:
                    if (check_prime(1111))
                        cout << "Yes\n";
                    else
                        cout << "No\n";
                    break;
                case 5:
                    if (check_prime(11111))
                        cout << "Yes\n";
                    else
                        cout << "No\n";
                    break;
                case 6:
                    cout << "No\n";
                    break;
                case 7:
                    if (check_prime(1111111))
                        cout << "Yes\n";
                    else
                        cout << "No\n";
                break;
            }
 
            continue;
        }
 
        if (k > 1)
            cout << "No\n";
        else
            if (check_prime(x))
                cout << "Yes\n";
            else
                cout << "No\n";
    }
 
    return 0;
}
