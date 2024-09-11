// ACCEPTED

class Solution {
public:
    int number_of_ones(int num)
    {
        int answer = 0;

        while(num != 0)
        {
            answer += num%2;

            num = num >> 1;
        }

        return answer;
    }

    int minBitFlips(int start, int goal)
    {
        return number_of_ones(start^goal);
    }
};
