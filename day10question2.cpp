class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        vector<Node*> q;
        vector<int> h;
        search(q, root, target);
        
        int res = 0, prev = q[0]->data;
        int n = q.size();
        for(int i=1; i < n; i++){
            Node *temp = q[i];
            if(temp->left == NULL || temp->right == NULL){
                h.push_back(1);
            }else if(temp->left->data == prev){
                h.push_back(height(temp->right) + 1);
            }else{
                h.push_back(height(temp->left) + 1);
            }
            prev = temp->data;
        }
        
        int mx = -1;
        for(int i=n-2; i >= 0; i--){
            mx = max(mx+1, h[i]);
        }

        res = max(mx+1, height(q[0])) - 1;
        return res;
    }
    
    int height(Node *root){
        if(root == NULL) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool search(vector<Node*> &q, Node *root, int target){
        if(root == NULL) return false;
        
        if(root->data == target){
            q.push_back(root);
            return true;
        }
        
        if(search(q, root->left, target)){
            q.push_back(root);
            return true;
        }
        
        if(search(q, root->right, target)){
            q.push_back(root);
            return true;
        }
        
        return false;
    }
};