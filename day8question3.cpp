class Solution{
public:
    int isValid(vector<vector<int>> arr){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(arr[i][j] == 0)
                    continue;
                
                for(int k=0;k<9;k++)
                    if(k != i && arr[i][j] == arr[k][j])
                        return 0;
                
                for(int k=0;k<9;k++)
                    if(k != j && arr[i][j] == arr[i][k])
                        return 0;
            }
        }
        
        int startI = 0, startJ = 0;
        for(int c = 0; c < 9 ; c++){
            vector<bool> found(9, false);
            for(int i=startI; i < startI+3; i++){
                for(int j=startJ; j < startJ + 3; j++){
                    if(arr[i][j] == 0)
                        continue;
                    
                    if(found[arr[i][j] - 1])
                        return 0;
                    found[arr[i][j]-1] = true;
                }
            }
            
            startJ += 3;
            if(startJ == 9){
                startJ = 0;
                startI += 3;
            }
        }
        
        return 1;
    }
};