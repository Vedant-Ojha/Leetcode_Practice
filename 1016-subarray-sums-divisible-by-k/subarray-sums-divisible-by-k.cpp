class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;
        int sum = 0, count = 0;

        for(int num : nums){
            sum += num;
            int rem = ((sum % k) + k) % k;
            count += freq[rem];
            freq[rem]++;
        }
        return count;

    }
};