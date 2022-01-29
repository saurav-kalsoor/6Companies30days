class Solution {
public:
    
    double radius, x_center, y_center;
    
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double random = rand() / (RAND_MAX*1.0);
        double r = sqrt(random)*radius;
        random = rand() / (RAND_MAX*1.0);
        double theta = random * (360.0);
        
        
        return {x_center + r * cos(theta), y_center + r * sin(theta)};
    }
};

