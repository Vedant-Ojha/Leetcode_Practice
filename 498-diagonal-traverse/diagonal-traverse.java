class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int te = mat.length * mat[0].length;
        int ans[] = new int[te];
        int r = 0; 
        int c = 0;
        int index = 0;
        boolean up = true;
        while(r<mat.length && c< mat[0].length){
            //up
            if(up){
                while(r>0 && c<mat[0].length-1){
                    ans[index] = mat[r][c];
                    index++;
                    r--;
                    c++;
                }
                ans[index] = mat[r][c];
                index++;
                if(c==mat[0].length-1){
                    r++;
                }
                else{
                    c++;
                }
            }
            else{
                while(r<mat.length-1 && c>0){
                    ans[index] = mat[r][c];
                    index++;
                    r++;
                    c--;
                }
                ans[index] = mat[r][c];
                index++;
                if(r==mat.length-1){
                    c++;
                }
                else{
                    r++;
                }
            }
            up=!up;
        }
        return ans;
    }
}