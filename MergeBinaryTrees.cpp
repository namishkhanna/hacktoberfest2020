class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL and t2 == NULL)return NULL;
        else if (t1 == NULL)return t2;
        else if (t2 == NULL)return t1;

        TreeNode* newnode = new TreeNode(t1->val + t2->val);
        newnode->left = mergeTrees(t1->left, t2->left);
        newnode->right = mergeTrees(t1->right, t2->right);

        return newnode;

    }
};