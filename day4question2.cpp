class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *res = new int[2];
       
        for(int i=0; i < n; i++) arr[i]--;
       
        for(int i=0; i < n; i++){
            if(arr[arr[i]%n] < n)
                arr[arr[i]%n] += n;
            else
                res[0] = arr[i]%n + 1;
        }
        
        for(int i=0; i < n; i++){
            if(arr[i] < n){
                res[1] = i + 1;
            }
        }
        return res;
    }
};