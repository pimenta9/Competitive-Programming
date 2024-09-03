// ACCEPTED!

class Solution {
public:
    int char2int(char c)
    {
        c = c - 'a' + 1;

        int x = c / 10;

        x += c % 10;

        return x;
    }

    int sumIntDigits(int n)
    {
        int ans = 0;

        while(n)
        {
            ans += n % 10;

            n /= 10;
        }

        return ans;
    }

    int getLucky(string s, int k)
    {
        int n = 0;

        for(char c : s)
        {
            n += char2int(c);
        }

        k--;
        while(k--)
            n = sumIntDigits(n);

        return n;
    }
};
