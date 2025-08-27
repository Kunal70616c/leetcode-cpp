// 22. Generate Parentheses
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // n => n*2 no of peranthesis

        backtrack(result, "", 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& result, string curr, int open, int close,
                   int n) {
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }
        if (open < n) {
            backtrack(result, curr + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(result, curr + ")", open, close + 1, n);
        }
    }
};
