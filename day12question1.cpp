class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        vector<int> res;
        int top = 0, bottom = r-1, left = 0, right = c-1;
        
        while(top <= bottom && left <= right){
            for(int j=left; j <= right; j++)
                res.push_back(arr[top][j]);
            top++;
            
            for(int i=top; i <= bottom; i++)
                res.push_back(arr[i][right]);
            right--;
            
            if(top <= bottom && left <= right){
                for(int j=right; j >= left; j--)
                res.push_back(arr[bottom][j]);
                bottom--;
                
                for(int i=bottom; i >= top; i--)
                    res.push_back(arr[i][left]);
                left++;
            }
        }
        
        return res;
    }
};