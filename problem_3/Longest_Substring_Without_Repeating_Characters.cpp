// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLengthSeen = 0;
        int left = 0, right = 0; // Pointers
        unordered_map<char, int> lastSeen;

        // Loop for window
        for (right = 0; right < s.size(); right++) {
            if (lastSeen.find(s[right]) != lastSeen.end()) {
                left = max(left, lastSeen[s[right]] + 1);
            }
            lastSeen[s[right]] = right;
            maxLengthSeen = max(maxLengthSeen, right - left + 1);
        }
        return maxLengthSeen;
    }
};
