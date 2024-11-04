// ACCEPTED!

class Solution {
public:
    string compressedString(string word)
    {
        string comp;

        int length = 1;
        char c = word[0];
        for(int i = 1; word[i] != '\0'; i++)
        {
            if (word[i] != c || length == 9)
            {
                comp.push_back(length + '0');
                comp.push_back(c);

                length = 1;
                c = word[i];
            }
            else
                length++;
        }
        comp.push_back(length + '0');
        comp.push_back(c);

        return comp;
    }
};
