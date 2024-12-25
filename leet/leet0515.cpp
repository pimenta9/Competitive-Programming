// ACCEPTED!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        if (root == nullptr)
            return {};

        vector<int> answer;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            TreeNode* node = q.front().first;
            int row = q.front().second;
            q.pop();

            if (row+1 > answer.size())
            {
                answer.resize(row+1);
                answer[row] = node->val;
            }
            else
                if (node->val > answer[row])
                    answer[row] = node->val;

            if (node->right != nullptr)
                q.push(make_pair(node->right, row+1));
            if (node->left != nullptr)
                q.push(make_pair(node->left, row+1));
        }

        return answer;
    }
};
