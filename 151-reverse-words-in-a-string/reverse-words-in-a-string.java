class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String str[] = s.split(" +");
        String ans = "";
        for(int i = str.length-1;i>=0;i--){
            ans= ans+str[i]+" ";
        }
        return ans.trim();
    }
}