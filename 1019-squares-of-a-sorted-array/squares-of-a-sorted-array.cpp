class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int right = n-1, left = 0;
        for(int i = n-1; i>=0; i--){
            int x;
            if(abs(nums[left])<abs(nums[right])){
                x = nums[right];
                right--;
            }else{
                x = nums[left];
                left++;
            }
            result[i] = x*x;
        }
        return result;
    }
};