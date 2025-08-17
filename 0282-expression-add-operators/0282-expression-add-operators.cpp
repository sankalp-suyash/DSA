class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }

    void backtrack(string& num, long target, int index, long value, long prev,
                   string expr, vector<string>& res) {
        if (index == num.size()) {
            if (value == target)
                res.push_back(expr);
            return;
        }

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0') {
                break;
            }

            string part = num.substr(index, i - index + 1);
            long cur = stol(part);

            if (index == 0) {
                backtrack(num, target, i + 1, cur, cur, part, res);
            } else {
                backtrack(num, target, i + 1, value + cur, cur,
                          expr + "+" + part, res);
                backtrack(num, target, i + 1, value - cur, -cur,
                          expr + "-" + part, res);
                backtrack(num, target, i + 1, value - prev + prev * cur,
                          prev * cur, expr + "*" + part, res);
            }
        }
    }
};
