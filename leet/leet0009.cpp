// ACCEPTED! //

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);

        int a = 0;
        int b = s.size() - 1;

        while (b > a)
        {
            if (s[a] != s[b]) return false;

            a++;
            b--;
        }

        return true;
    }
};