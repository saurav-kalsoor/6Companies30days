 class Solution{   
public:
    string printMinNumberForPattern(string str){
        int z = 1, i = 0, n = str.length();
        string res;
    
        while(i < n){
            if(str[i] == 'I'){
                res.push_back(z + '0');
                z++;
            }else{
                string temp;
                while(i < n && str[i] == 'D'){
                    i++;
                    temp.push_back(z + '0');
                    z++;
                }

                temp.push_back(z + '0');
                z++;
                
                reverse(temp.begin(), temp.end());
                res.append(temp);
            }
            i++;
        }
        
        if(str[n-1] == 'I')
            res.push_back(z + '0');
        return res;
    }
};