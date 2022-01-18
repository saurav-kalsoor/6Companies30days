class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int st = 0, end = 0;
        long long sum = 0;
        
        while(end < n){
            sum += arr[end];
            while(sum > s && st <= end){
                sum -= arr[st];
                st++;
            }
            
            if(sum == s){
                return {st+1, end+1};
            }
            end++;
        }
        
        
        return {-1};
    }
};