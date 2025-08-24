// 70. Climbing Stairs
//You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// <Its a Fibonacci Series>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n; // two ways
        int a = 1, b = 2, ways;
        for (int i = 3; i <= n; i++) {
            ways = a + b;
            a = b;
            b = ways;
        }
        return b;
    }
};

