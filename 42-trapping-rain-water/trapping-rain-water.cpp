// Approach1 :- Using arrays
// TC:- O(n)
// SC:- O(n)
//#############################################################################################################################################################
class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};
//###########################################################################################################################################################
//Approach2 :- Using Two Pointers
//TC :- O(n)
// SC :- O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;

        int leftMax = 0;
        int rightMax = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {

            // Update maximum height seen from both sides
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // Water level cannot exceed the smaller boundary
            int waterLevel = min(leftMax, rightMax);

            if (height[left] < height[right]) {

                // Water trapped at current left position
                water += max(0, waterLevel - height[left]);

                left++;
            }
            else {

                // Water trapped at current right position
                water += max(0, waterLevel - height[right]);

                right--;
            }
        }

        return water;
    }
};
