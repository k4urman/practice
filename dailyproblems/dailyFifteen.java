/*
Create Maximum Number

You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
Return an array of the k digits representing the answer.

Example 1:
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]

Example 2:
Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]

Example 3:
Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
*/

class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] ans = new int[k];
        
        for (int x = Math.max(0, k - nums2.length); x <= Math.min(k, nums1.length); ++x) {
            // Create the first array of the maximum numbers
            int[] stk1 = new int[x];
            int top1 = -1;
            int remain1 = nums1.length - x;
            for (int num : nums1) {
                while (top1 >= 0 && stk1[top1] < num && remain1 > 0) {
                    --top1;
                    --remain1;
                }
                if (top1 + 1 < x) {
                    stk1[++top1] = num;
                } else {
                    --remain1;
                }
            }

            // Create the second array of the maximum numbers
            int[] stk2 = new int[k - x];
            int top2 = -1;
            int remain2 = nums2.length - (k - x);
            for (int num : nums2) {
                while (top2 >= 0 && stk2[top2] < num && remain2 > 0) {
                    --top2;
                    --remain2;
                }
                if (top2 + 1 < (k - x)) {
                    stk2[++top2] = num;
                } else {
                    --remain2;
                }
            }

            // Merge the two arrays
            int[] merged = new int[k];
            int i = 0, j = 0;
            for (int idx = 0; idx < k; ++idx) {
                if (i < stk1.length && (j >= stk2.length || compare(stk1, stk2, i, j))) {
                    merged[idx] = stk1[i++];
                } else {
                    merged[idx] = stk2[j++];
                }
            }

            // Compare merged array with the current answer
            if (compare(merged, ans, 0, 0)) {
                ans = merged;
            }
        }
        return ans;
    }

    private boolean compare(int[] nums1, int[] nums2, int i, int j) {
        if (i >= nums1.length) return false;
        if (j >= nums2.length) return true;
        if (nums1[i] > nums2[j]) return true;
        if (nums1[i] < nums2[j]) return false;
        return compare(nums1, nums2, i + 1, j + 1);
    }
}
