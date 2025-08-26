// 18. 4Sum 
/* 
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/ 

// NOT OPTIMIZED !!

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, l, r;
        int ips = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (i = 0; i < ips - 3; i++) {
            for (j = i + 1; j < ips - 2; j++) {
                // init left & right pointers
                l = j + 1;
                r = ips - 1;
                while (l < r) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // increment
                        l++;
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        auto newEnd = unique(res.begin(), res.end());
        res.erase(newEnd, res.end());
        return res;
    }
};

