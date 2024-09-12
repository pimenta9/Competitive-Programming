// ACCEPTED!

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        vector<bool> letters('z'-'a');

        for(char c : allowed)
            letters[c - 'a'] = true;

        int numConsistentStrings = 0;

        for(string s : words)
        {
            for(char c : s)
                if(letters[c - 'a'] == false)
                {
                    numConsistentStrings--;
                    break;
                }

            numConsistentStrings++;
        }

        return numConsistentStrings;
    }
};
