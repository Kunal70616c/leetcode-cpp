// 55. Jumping Game
/* 
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/ 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetPos = nums.size() - 1;
        for (int i = targetPos - 1; i >= 0; i--) {
            if ((i + nums[i]) >= targetPos){
                targetPos = i;
            }
        }
        if (targetPos == 0) {
            return true;
        }
        return false;
    }
};
