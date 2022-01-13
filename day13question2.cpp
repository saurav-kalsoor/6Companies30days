class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        Node *temp1 = root;
        queue<Node*> q;
        q.push(temp1);
       
        while(!q.empty()){
            int n = q.size();
            while(n){
                Node *temp = q.front();
                q.pop();
               
                if(n != 1)
                    temp->nextRight = q.front();
                else
                    temp->nextRight = NULL;
                
                if(temp->left != NULL) q.push(temp->left);
                
                if(temp->right != NULL) q.push(temp->right);
            
                n--;
            }
        }
    }    
      
};