class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int, int> mp;
        
        for(int num : nums){
            int rem = num%k;
            if(mp.find(k - rem) != mp.end()){
                mp[k - rem]--;
                if(mp[k - rem] == 0)
                    mp.erase(k-rem);
            }else{
                mp[rem]++;
            }
        }
        if(mp.find(0) != mp.end() && mp[0]%2 == 0){
            mp.erase(0);
        }
        return mp.empty();
    }
};