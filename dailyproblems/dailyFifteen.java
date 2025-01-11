class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] total = new int[nums1.length + nums2.length];
        Arrays.sort(total);
        for (int i = 0, j = total.length - 1; i < j; i++, j--) {
            int temp = total[i];
            total[i] = total[j];
            total[j] = temp;
        }
        int[] maxNum = new int[k];
        for(int i = 0; i < maxNum.length; i++){
            maxNum[i] = total[i];
        }
        return maxNum;
    }
}
