class Solution{
public:
    int minSteps(int D){
        int sum = 0, steps = 1;
        while(1){
            sum += steps;
            if(sum == D){
                return steps;
            }
            
            if(sum > D && (sum - D)%2 == 0){
                return steps;
            }
            steps++;
        }
        return 0;
    }
};