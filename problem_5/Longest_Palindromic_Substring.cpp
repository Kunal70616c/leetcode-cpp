// 5. Longest Palindromic Substring
//Given a string s, return the longest palindromic substring in s.
//
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, end=0, maxLen = 1;
        int n = s.length();
        if (n <= 1) {
            return s;
        }
        for (int i = 0; i < n-1; ++i) {
            // For Odd Case
            int left = i;
            int right = i;
            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                        left--;
                        right++;
                    }
                else {
                    break;
                }
                int len = (right - left - 1);
                if (len > maxLen) {
                    maxLen = len;
                    start = left + 1;
                    end = right - 1;
                }
            }
            // Even Case
            left = i, right = i + 1;
            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                        left--;
                        right++;
                    }
                else {
                    break;
                }
                int len = (right - left - 1);
                if (len > maxLen) {
                    maxLen = len;
                    start = left + 1;
                    end = right - 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
