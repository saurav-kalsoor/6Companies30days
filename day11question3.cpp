void rotate(vector<vector<int> >& arr)
{
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int lo = 0, hi = n-1;
        while(lo < hi){
            swap(arr[i][lo], arr[i][hi]);
            lo++;
            hi--;
        }
    }
    
    for(int i=1; i < n; i++){
        for(int j=0; j < i; j++)
            swap(arr[i][j], arr[j][i]);
    }
}
