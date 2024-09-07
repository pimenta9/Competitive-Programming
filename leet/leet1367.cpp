// ACCEPTED!

class Solution {
public:
    bool check(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
            return true;

        if(root == NULL)
            return false;

        if(head->val != root->val)
            return false;

        return (check(head->next, root->left) || check(head->next, root->right));
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(root == NULL)
            return false;

        if(check(head, root))
            return true;

        return (isSubPath(head, root->left) || isSubPath(head, root->right));
    }
};
