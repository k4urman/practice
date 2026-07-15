class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean check = false;
        for (int[] row : matrix) {
            for (int element : row) {
                if(element == target){
                    check = true;
                }
            }
        }
        return check;
    }
}
