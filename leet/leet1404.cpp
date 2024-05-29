// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int numSteps(string s)
{
    if (s == "1") return 0;

    int n = s.size();

    bool number[n + 1];

    // [1] [0] [1] [1] ...
    // 2^0 2^1 2^2 2^3 ...

    for (int i = 0; i < n; i++)
    {
        number[i] = (s[(n - 1) - i] - '0') ? true : false;
    }
    number[n] = false;

    int index = 0, steps = 0;

    while (true)
    {
        steps++;

        // odd -> add 1
        if (number[index] == true)
        {
            int i;
            for (i = index; number[i]; i++)
            {
                number[i] = false;
            }
            number[i] = true;
        }
        else // even -> divide by 2
        {
            index++;
        }

        if (index == (n - 1))
        {
            if (number[n] == true)
            {
                steps++;
                return steps;
            }
            else
            {
                return steps;
            }
        }
    }

    return 0;
}

int main ()
{
    string s = {"1101"};

    cout << numSteps(s) << endl;

    return 0;
}