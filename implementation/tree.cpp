class Node
{
  public:
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* root) {
    if(root) {
        preOrder(root->left);
        cout<<root->val;
        preOrder(root->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    preOrder(root);
}
