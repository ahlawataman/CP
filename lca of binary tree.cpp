class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* parent1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* parent2 = lowestCommonAncestor(root->right, p, q);
        if(parent1 && parent2)
            return root;
        else
            return parent1?parent1:parent2;
    }
};
