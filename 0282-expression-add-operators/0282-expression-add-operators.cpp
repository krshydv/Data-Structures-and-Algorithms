class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string path;
        backtrack(num, target, 0, 0, 0, path, result);
        return result;
    }

private:
    void backtrack(string& num, long target, int index, 
                   long value, long prev, 
                   string& path, vector<string>& result) {
        if (index == num.size()) {
            if (value == target) result.push_back(path);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long curr = stol(currStr);
            int len = path.size();

            if (index == 0) {
                path += currStr;
                backtrack(num, target, i + 1, curr, curr, path, result);
                path.resize(len);
            } else {
                path += "+" + currStr;
                backtrack(num, target, i + 1, value + curr, curr, path, result);
                path.resize(len);

                path += "-" + currStr;
                backtrack(num, target, i + 1, value - curr, -curr, path, result);
                path.resize(len);

                path += "*" + currStr;
                backtrack(num, target, i + 1, value - prev + prev * curr, prev * curr, path, result);
                path.resize(len);
            }
        }
    }
};