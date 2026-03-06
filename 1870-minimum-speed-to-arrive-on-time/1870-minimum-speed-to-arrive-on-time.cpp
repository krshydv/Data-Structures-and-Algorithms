class Solution {
public:
    
    bool canReach(vector<int>& dist, double hour, int speed) {
        double time = 0.0;
        int n = dist.size();
        
        for(int i = 0; i < n - 1; i++) {
            time += ceil((double)dist[i] / speed);
        }
        
        time += (double)dist[n-1] / speed;
        
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int left = 1, right = 1e7;
        int ans = -1;
        
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(canReach(dist, hour, mid)) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};