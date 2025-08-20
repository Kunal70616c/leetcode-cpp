//6. Zigzag Conversion


class Solution {
public:
    string convert(string s, int numRows) {

        int increment = 2 * (numRows - 1);
        string resStr = "";
        int size = s.size();
        // Base Case Check
        if (numRows == 1) {
            return s;
        } else {
            for (int i = 0; i < numRows; i++) {
                for (int j = i; j < size; j += increment) {
                    resStr += s[j];
                    if (i > 0 && i < numRows - 1) {
                        int diagIndex = j + increment - 2 * i;
                        if (diagIndex < size) {
                            resStr += s[diagIndex];
                        }
                    }
                }
            }
        }
        return resStr;
    }
};
