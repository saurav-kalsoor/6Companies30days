class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> a;
        ser(root, a);
        return a;
    }
    
    void ser(Node *root, vector<int> &a){
        if(root == NULL){
	      a.push_back(-1);
	      return;  
	    } 
	    
	    a.push_back(root->data);
	    ser(root->left, a);
	    ser(root->right, a);
    }
    //Function to deserialize a list and construct the tree.
    
    
    Node * deSerialize(vector<int> &a)
    {
        int i = -1;
        return deser(a, i);
    }
    
    Node* deser(vector<int> &a, int &i){
        i++;
        if(a[i] == -1) return NULL;
        Node *root = new Node(a[i]);
        root->left = deser(a, i);
        root->right = deser(a, i);
    }

};