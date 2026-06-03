class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                ans = min(ans, max(landFinish, waterStartTime[j]) + waterDuration[j]);
            }
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            int waterFinish = waterStartTime[j] + waterDuration[j];

            for (int i = 0; i < landStartTime.size(); i++) {
                ans = min(ans, max(waterFinish, landStartTime[i]) + landDuration[i]);
            }
        }

        return ans;
    }
};