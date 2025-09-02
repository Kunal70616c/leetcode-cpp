// 17. Letter Combinations of a Phone Number
/*
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/ 

class Solution {
public:
    vector<string> res;
    unordered_map<char, string> keyPad;
    void backTrack(int i, string currStr, string digits) {
        if (currStr.length() == digits.length()) {
            res.push_back(currStr);
            return;
        }
        for (auto c : keyPad[digits[i]]) {
            backTrack(i + 1, currStr + c, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Maping
        keyPad['2'] = "abc";
        keyPad['3'] = "def";
        keyPad['4'] = "ghi";
        keyPad['5'] = "jkl";
        keyPad['6'] = "mno";
        keyPad['7'] = "pqrs";
        keyPad['8'] = "tuv";
        keyPad['9'] = "wxyz";

        if (digits == "") {
            return {};
        }
        backTrack(0, "", digits);
        return res;
    }
};
