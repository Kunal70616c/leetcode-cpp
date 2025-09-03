// 34. Find First and Last Position of Element in Sorted Array
/*
 Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/ 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int foundAt = -1;
        if (nums.size() == 1 and nums[0] == target) {
            return {0, 0};
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                foundAt = mid;
                break;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        if (foundAt == -1) {
            return {-1, -1};
        }
        int firstOcc = foundAt;

        while ((firstOcc > 0) && (nums[firstOcc - 1] == target)) {
            firstOcc--;
        }

        int lastOcc = foundAt;
        while ((lastOcc < nums.size() - 1) && (nums[lastOcc + 1] == target)) {
            lastOcc++;
        }
        return {firstOcc, lastOcc};
    }
};
