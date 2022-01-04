void heapify(vll &arr, ll n, ll i){
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    if(left >= n) return;

    ll mx = left;
    if(right < n && arr[right] > arr[left]) mx = right;

    if(arr[i] < arr[mx]){
        swap(arr[i], arr[mx]);
        heapify(arr, n, mx);
    }
}

ll getTop(vll &arr, ll &n){
    ll mx = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr, n, 0);
    return mx;
}

vector<ll> getTopTen(vll &arr, ll n){
    vll res(10);

    for(ll i=(n/2)-1; i >= 0; i--)
        heapify(arr, n, i);

    for(ll i=0;i < 10; i++){
        res[i] = getTop(arr, n);
    }

    return res;
}