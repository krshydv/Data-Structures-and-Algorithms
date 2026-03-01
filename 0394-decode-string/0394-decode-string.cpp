class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> st;
        string curr;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                st.push(curr);
                num = 0;
                curr.clear();
            } else if (c == ']') {
                int k = counts.top();
                counts.pop();
                
                string temp = curr;
                curr = st.top();
                st.pop();
                
                while (k--) {
                    curr += temp;
                }
            } else {
                curr += c;
            }
        }
        
        return curr;
    }
};