class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] rand = new int[nums1.length + nums2.length];


        for (int i = 0; i < nums1.length; i++) {
            rand[i] = nums1[i];
        }

        for (int i = 0; i < nums2.length; i++) {
            rand[nums1.length + i] = nums2[i];
        }

        Arrays.sort(rand);

        if (rand.length % 2 == 0) {
            return (double) (rand[rand.length / 2 - 1] + rand[rand.length / 2]) / 2;
        } else { 
            return (double) rand[rand.length / 2];
        }
    }
}
