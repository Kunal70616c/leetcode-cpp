// 8. String to Integer (atoi)
//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
/*
The algorithm for myAtoi(string s) is as follows:

1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 231 - 1.

Return the integer as the final result.
*/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // Skipping WhiteSapce
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Identifying First Sign
        while (i < n && (s[i] == '+' || s[i] == '-')) {
            char firstSign = s[i];
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                return result;
            }
            if (firstSign == '-') {
                sign = -1;
            }
        }

        // Finding Digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = (result * 10) + digit;

            // Range Control (as range mustbe within int range)
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }
        return (sign * result);
    }
};
