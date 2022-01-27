class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        f(node);
    }
    
    int f(Node *node){
        if(node == NULL) return 0;
        int lSum = f(node->left);
        int rSum = f(node->right);
        
        int prev = node->data;
        node->data = lSum + rSum;
        return node->data + prev;
    }
};