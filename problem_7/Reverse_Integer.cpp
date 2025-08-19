// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        long int nn = 0;
        while (x != 0) {
            nn *= 10;
            nn += (x % 10);
            x = x / 10;
        }
        if (nn > INT_MAX || nn < INT_MIN)
            return 0;
        else
            return nn;
    }
};
