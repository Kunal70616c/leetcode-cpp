//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string resStr = "";

        // Strs empty
        if (strs.empty()) {
            return "";
        }

        int minStrLen = strs[0].length();

        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < strs[0].length()) {
                minStrLen = strs[i].length();
            }
        }
        for (int k = 0; k < minStrLen ; k++) {
            char chk = strs[0][k];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][k] != chk) {
                    return resStr;  // mismatch found
                }
            }
            resStr += chk;
        }
        return resStr;
    }
};
