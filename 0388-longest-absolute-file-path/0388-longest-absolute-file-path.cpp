class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> depthLength;
        depthLength[0] = 0;
        
        int maxLen = 0;
        int i = 0;
        int n = input.size();
        
        while (i < n) {
            int depth = 0;
            while (i < n && input[i] == '\t') {
                depth++;
                i++;
            }
            
            int start = i;
            bool isFile = false;
            
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                i++;
            }
            
            int len = i - start;
            
            if (isFile) {
                maxLen = max(maxLen, depthLength[depth] + len);
            } else {
                depthLength[depth + 1] = depthLength[depth] + len + 1;
            }
            
            i++;
        }
        
        return maxLen;
    }
};