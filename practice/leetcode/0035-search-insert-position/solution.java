class Solution {
    public int searchInsert(int[] nums, int target) {
        int output = 0;

        if(nums[nums.length-1] < target){
            output = nums.length;
        }
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == target){
                output = i;
            }else{
                if(i != nums.length-1 && nums[i] < target && nums[i+1] > target){
                    output = i+1;
                }
            }
        }
        return output;
    }
}
