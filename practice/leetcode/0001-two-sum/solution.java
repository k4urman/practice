class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] val = new int[2];
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == target- nums[i]) {
                    val[0] = i;
                    val[1] = j;
                }
            }
        }
        return val;
    }
}
