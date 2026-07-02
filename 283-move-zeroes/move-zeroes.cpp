class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int end = 0;
        while(end< nums.size()){
            if(nums[end] != 0){
                int temp = nums[st];
                nums[st] = nums[end];
                nums[end] = temp;
                st++;
            }
            end++;
        }
            
    }
    
};