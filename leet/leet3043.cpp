// ACCEPTED (beats 50%)

class Solution {
public:
    typedef struct TrieNode
    {
        vector<TrieNode*> children = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    } TrieNode;

    // debug
    void printTrie(TrieNode* root)
    {
        cout << "-------------\n";

        queue<TrieNode*> q;

        q.push(root);

        while(!q.empty())
        {
            TrieNode* node = q.front();
            q.pop();

            for(int i = 0; i < 10; i++)
            {
                if(node->children[i] == nullptr)
                    continue;
                
                cout << i << " ";

                q.push(node->children[i]);
            }

            cout << endl;
        }

        cout << "-------------\n";
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        TrieNode* root = new TrieNode;

        for(int num : arr1)
        {
            string numStr = to_string(num);

            TrieNode* node = root;

            for(char d : numStr)
            {
                int digit = d - '0';

                if(node->children[digit] == nullptr)
                    node->children[digit] = new TrieNode;

                node = node->children[digit];
            }
        }

        int maxLength = 0;

        for(int num : arr2)
        {
            cout << num << endl;
            string numStr = to_string(num);

            TrieNode* node = root;

            int length = 0;

            for(char d : numStr)
            {
                int digit = d - '0';

                if(node->children[digit] == nullptr)
                    break;

                length++;

                node = node->children[digit];
            }

            if(length > maxLength)
                maxLength = length;
        }

        return maxLength;
    }
};
