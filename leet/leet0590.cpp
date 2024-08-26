// ACCEPTED!

class Solution {
public:

    vector<int> concatenate(vector<int> a, vector<int> b)
    {
        vector<int> c;

        for(int x : a)
            c.push_back(x);

        for(int x : b)
            c.push_back(x);

        return c;
    }

    vector<int> postorder(Node* root)
    {
        if(root == NULL)
            return {};

        vector<int> traversal;

        for(Node* x : root->children)
        {
            vector<int> current = postorder(x);

            traversal = concatenate(traversal, current);
        }

        traversal.push_back(root->val);

        return traversal;
    }
};
