int height(TreeNode* root, bool &res) {
  if(!res) return 0;
  if(!root) return 0;
  int l = height(root->left, res);
  int r = height(root->right, res);
  // CONDITION TO CHECK
  /* EX.
  if (abs(l-r)>1) {
    // DO SOMETHING
    res = false;
    return 0;
  }
  */
  return 1 + max(l,r);
}
