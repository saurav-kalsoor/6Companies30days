class Solution {
public:

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> arr(n);
        long long mod = 1e9 + 7;
        for(int i=0; i < n; i++){
            arr[i] = {efficiency[i], speed[i]};
        }
        
        sort(arr.begin(), arr.end(), greater<pair<long long, long long>>());
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(arr[0].second);

        long long res = arr[0].first * arr[0].second, sum = arr[0].second;

        for(int i=1; i < n; i++){
            if(pq.size() == k){
                sum -= pq.top();
                pq.pop();
            }

            pq.push(arr[i].second);
            sum += arr[i].second;

            res = max(res, (long long)(arr[i].first * sum));
        }
        res = res%mod;
        return (int)res;
    }
};