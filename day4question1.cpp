vector<ll> getTopTen(vll &arr, ll n){
    priority_queue<ll, vector<ll>, greater<ll>> mnHeap;  
    vll res;
    for (ll a : arr) {
        mnHeap.push(a);
        if (mnHeap.size() > 10) 
            mnHeap.pop();
    }

    while(!mnHeap.empty()){
        res.push_back(mnHeap.top());
        mnHeap.pop();
    }
    return res;
}