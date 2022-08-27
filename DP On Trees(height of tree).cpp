int height(TreeNode* root, bool &res) {
  
  // BASE CONDITION
  if(!res) return 0;
  if(!root) return 0;
  
  // HYPOTHESIS
  int l = height(root->left, res);
  int r = height(root->right, res);

  // AM I THE ANSWER ?
  if (abs(l-r)>1) {
    // DO SOMETHING
    res = false;
    return 0;
  }
  
  // INDUCTION (PASSING SOME CALCULATION TO HELP PARENT NODE FIND IT'S ANSWER)
  return 1 + max(l,r);
}
