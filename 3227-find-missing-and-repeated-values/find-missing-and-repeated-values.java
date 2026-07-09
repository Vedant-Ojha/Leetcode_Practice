class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] ans = new int[2];
        int n = grid.length;
        int nSquare = n * n;
        HashMap<Integer ,Integer> map = new HashMap<>();
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j <grid[0].length ; j++){
                map.put(grid[i][j],map.getOrDefault(grid[i][j],0)+1);
            }
        }
        for(int i = 1 ; i <= nSquare ; i++){
            int count  = map.getOrDefault(i,0);
            if(count == 2){
                ans[0] = i;
            }else if(count == 0){
                ans[1] = i;
            }
        }
        return ans;
    }
}