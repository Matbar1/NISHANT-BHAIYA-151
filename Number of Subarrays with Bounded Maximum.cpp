class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
         int count = 0;
        int start = -1; // The start index of the subarray
        int prevCount = 0; // The count of valid subarrays ending at the previous index
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                start = i;
                prevCount = 0;
            } else if (nums[i] >= left) {
                prevCount = i - start;
            }
            
            count += prevCount;
        }
        
        return count;
    }
};
        
