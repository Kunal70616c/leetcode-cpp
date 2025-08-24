// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

class Solution {
public:
    string addBinary(string a, string b) {
        int aSize = a.length() - 1;
        int bSize = b.length() - 1;
        string res = "";
        int carry = 0;
        while (aSize >= 0 || bSize >= 0 || carry) {
            int sum = carry;
            if (aSize >= 0) {
                sum += a[aSize--] - '0';
            }
            if (bSize >= 0) {
                sum += b[bSize--] - '0';
            }
            res += (sum % 2) + '0';
            carry = (sum / 2);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
