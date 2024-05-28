// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

bool buddyStrings(string s, string goal)
{
    if (s.size() != goal.size()) return false;

    map<int, bool> m;
    if (s == goal)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == true) return true;

            m[s[i]] = true;
        }
    }

    int wrongIndex1 = -1, wrongIndex2, totalWrongs = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != goal[i])
        {
            totalWrongs++;

            if (wrongIndex1 == -1)
                wrongIndex1 = i;
            else
                wrongIndex2 = i;
        }
    }

    if (totalWrongs != 2) return false;

    if (s[wrongIndex1] == goal[wrongIndex2] && s[wrongIndex2] == goal[wrongIndex1])
        return true;

    return false;
}

int main ()
{
    string s1 = {"ab"}, s2 = {"ab"};

    cout << buddyStrings(s1, s2) << endl;

    return 0;
}