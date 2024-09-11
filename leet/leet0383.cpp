// ACCEPTED!

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> letter;

        for(char c : magazine)
            letter[c]++;

        for(char c : ransomNote)
            if(letter[c] == 0)
                return false;
            else
                letter[c]--;

        return true;
    }
};
