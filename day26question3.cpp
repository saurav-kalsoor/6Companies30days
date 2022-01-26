class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int aMoves = 0, bMoves = 0, a = 0, b = 0;
        
        for(int i=0; i < n; i++){
            if(s[i] == 'A'){
                a++;
                bMoves += max(0, b - 2);
                b = 0;
            }else{
                b++;
                aMoves += max(0, a - 2);
                a = 0;
            }
        }
        bMoves += max(0, b - 2);
        aMoves += max(0, a - 2);
        
        return aMoves > bMoves;
    }
};