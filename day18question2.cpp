class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int n = str.size();
        bool found = false;
        int res = 0;
        for(int i=0; i < n; i++){
            if(str[i] == '-'){
                found = true;
                continue;
            } 
            if(str[i] < '0' || str[i] > '9') return -1;
            res *= 10;
            res += (str[i] - '0');
        }
        if(found) res *= -1;
        return res;
    }
};