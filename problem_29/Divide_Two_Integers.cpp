// 29. Divide Two Integers
/*

   Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
*/ 
 class Solution {
public:
    int divide(int dividend, int divisor) {
        long res = 0;
        if(dividend == INT_MIN && divisor ==-1){
            return (INT_MAX);
        }else if(dividend == INT_MAX && divisor ==-1){
            return (INT_MIN +1);
        }
        long cdiv = labs(dividend);
        long locDiv = labs(divisor);
        while (cdiv >= locDiv) {
            cdiv -= locDiv;
            res++;
        }
        if(dividend<0 && divisor <0){
            return res;
        }else if(dividend<0 || divisor <0){
            res = res *(-1);
        }
        return res;
    }
};
