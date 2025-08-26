// 69. Sqrt(x)
/*

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/ 
class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 1;
        // base case
        if (x == 0)
            return 0;

        // Binary Search
        while (low <= high) {
            long long mid = low + ((high - low) / 2);
            if ((mid * mid) == x) {
                return mid;
            } else if ((mid * mid) < x) {
                low = mid + 1;
                // imperfect square has to be rounded down
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
        // Complexity O(logn)
    }
};
