int subSum(Node *root, int x, int &count){
    if(root == NULL) return 0;
    
    int s = root->data;
    s += subSum(root->left, x, count);
    s += subSum(root->right, x, count);
    
    if(s == x) count++;
    return s;
}

int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
	subSum(root, X, count);
	return count;
}