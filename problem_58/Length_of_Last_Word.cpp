// 58. Length of Last Word
//Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpaceAt = -1;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && isalpha(s[i + 1])) {
                lastSpaceAt = i;
            }
        }
        int j = lastSpaceAt + 1;
        while (j < s.length() || s[j] == ' ') {
            if (isalpha(s[j]))
                count++;

            j++;
        }
        return count;
    }
};
