class Solution{
    public:
 
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int mx = arr[0][0], mn;
        int l, r, len;
        for(int i=0; i < k; i++){
            pq.push({arr[i][0], {i, 0}});
            mx = max(arr[i][0], mx);
            l = min(l, arr[i][0]);
        }
        
        mn = l;
        r = mx;
        len = r - l;
        while(1){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            
            int val = p.first, i = p.second.first, j = p.second.second;
            if(j + 1 < n){
                pq.push({arr[i][j+1], {i, j+1}});
                mx = max(mx, arr[i][j+1]);
            }else{
                return {l, r};
            }
            
            
            while(!pq.empty() && pq.top().first == val){
                p = pq.top();
                pq.pop();
                val = p.first, i = p.second.first, j = p.second.second;
                
                if(j + 1 < n){
                    pq.push({arr[i][j+1], {i, j+1}});
                    mx = max(mx, arr[i][j+1]);
                }else{
                    return {l, r};
                }
            }
            
            mn = pq.top().first;
            if(mx - mn < len){
                len = mx - mn;
                l = mn;
                r = mx;
            }
        }
        return {mn, mx};
    }
};