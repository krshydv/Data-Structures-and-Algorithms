class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> st;

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push_back(id);
            } else {
                while (!st.empty() && healths[id] > 0) {
                    int j = st.back();
                    if (healths[j] < healths[id]) {
                        st.pop_back();
                        healths[id]--;
                        healths[j] = 0;
                    } else if (healths[j] == healths[id]) {
                        st.pop_back();
                        healths[j] = 0;
                        healths[id] = 0;
                        break;
                    } else {
                        healths[j]--;
                        healths[id] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) res.push_back(healths[i]);
        }
        return res;
    }
};