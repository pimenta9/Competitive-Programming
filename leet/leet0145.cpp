vector<int> concatenate(vector<int> a, vector<int> b)
{
    vector<int> c;

    for(int x : a)
        c.push_back(x);

    for(int x : b)
        c.push_back(x);

    return c;
}

vector<int> postorderTraversal(TreeNode* root)
{
    if(root == NULL)
        return {};

    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);

    vector<int> answer = concatenate(left, right);
    answer.push_back(root->val);

    return answer;
}
