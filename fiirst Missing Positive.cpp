class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
        
        // Step 1: Move all positive integers to their respective indices
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positive integers are present from 1 to n, return n + 1
        return n + 1;
    }
};
        
    