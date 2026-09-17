class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int inf = 1e9;
        vector<int> best(n, inf);

        int left = 0;
        int sum = 0;
        int smallest = inf;
        int answer = inf;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int length = right - left + 1;

                if (left > 0 && best[left - 1] != inf) {
                    answer = min(answer, length + best[left - 1]);
                }

                smallest = min(smallest, length);
            }

            best[right] = smallest;
        }

        return answer == inf ? -1 : answer;
    }
};