class Solution {
public:
    double r, xc, yc;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double theta = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double dist = sqrt((double) rand() / RAND_MAX) * r;
        
        double x = xc + dist * cos(theta);
        double y = yc + dist * sin(theta);
        
        return {x, y};
    }
};