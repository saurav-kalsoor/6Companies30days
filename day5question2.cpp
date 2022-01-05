class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st = 0, end = 0, n = nums.size(), res = n+1, sum = 0;
        
        while(st < n && end < n){
            sum += nums[end];
            if(sum >= target){
                res = min(res, end - st + 1);
                while(st <= end && sum - nums[st] >= target){
                    sum -= nums[st];
                    st++;
                }
                res = min(res, end - st + 1);
            }
            end++;
        }
            
            
        return res%(n+1);
    }
};