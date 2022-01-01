class Solution {
  public:
    
    bool check(int x[], int a[], int b[]){
        return ( x[0] >= a[0] && x[0] <= b[0] && x[1] <= a[1] && x[1] >= b[1]);
    }
    
    bool check2(int l1[], int r1[], int l2[], int r2[]){
        return (l1[0] <= l2[0] && r1[0] >= r2[0] && l1[1] <= l2[1] && r1[1] >= r2[1]);
    }
  
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        int x[2], y[2], a[2], b[2];
        x[0] = r1[0];
        x[1] = l1[1];
        y[0] = l1[0];
        y[1] = r1[1];
        
        a[0] = r2[0];
        a[1] = l2[1];
        b[0] = l2[0];
        b[1] = r2[1];
        
        return (check(x, l2, r2) || check(y, l2, r2) || check(l1, l2, r2) || check(r1, l2, r2) || 
                 check(a, l1, r1) || check(b, l1, r1) || check(l2, l1, r1) || check(r2, l1, r1) ||
                 (check2(l1, r1, l2, r2) || check2(l2, r2, l1, r1)));
    }
};