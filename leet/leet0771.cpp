// ACCEPTED!

class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<bool> isJewel('z' + 1, false);

        for (char j : jewels)
            isJewel[j] = true;

        int answer = 0;

        for (char s: stones)
            if (isJewel[s])
                answer++;

        return answer;
    }
};
