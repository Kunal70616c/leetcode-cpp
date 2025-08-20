// 4.Median of Two Sorted Arrays
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        // Calculate the size of the merged array
        int n = nums1.size() + nums2.size();

        // Create a new vector to store the merged elements
        std::vector<int> mergedArray(n);

        // Copy elements from arr1
        for (int i = 0; i < nums1.size(); ++i) {
            mergedArray[i] = nums1[i];
        }

        // Copy elements from arr2
        for (int i = 0; i < nums2.size(); ++i) {
            mergedArray[nums1.size() + i] = nums2[i];
        }

        sort(mergedArray.begin(), mergedArray.end());

        // Calculating median
        // for Odd size
        if (n % 2 != 0) {
            median = mergedArray[n / 2];
        }
        // For Even size
        else {
            median =
                ((double)(mergedArray[n / 2] + mergedArray[(n / 2) - 1]) / 2);
        }
        return median;
    }
};
