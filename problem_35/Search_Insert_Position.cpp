// 38. Search Insert Position
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // finding element
        auto itr = find(nums.begin(), nums.end(), target);
        if (itr != nums.end()) {
            return distance(nums.begin(), itr);
        } else {
            nums.push_back(target);         // adding element
            sort(nums.begin(), nums.end()); // sorting array
            itr = find(nums.begin(), nums.end(), target);
        }
        return distance(nums.begin(), itr);
    }
};
