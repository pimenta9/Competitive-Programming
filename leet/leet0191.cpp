/ ACCEPTED!

class Solution {
public:
    int hammingWeight(int n)
    {
        int answer = 0;

        while (n)
        {
            answer += n % 2;
            n /= 2;
        }

        return answer;
    }
};
