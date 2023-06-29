class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
        return 0;

    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; i++) {
        // Swap maxProduct and minProduct if the current number is negative
        if (nums[i] < 0)
            std::swap(maxProduct, minProduct);

        // Update maxProduct and minProduct
        maxProduct = std::max(nums[i], maxProduct * nums[i]);
        minProduct = std::min(nums[i], minProduct * nums[i]);

        // Update the maximum product
        result = std::max(result, maxProduct);
    }

    return result;
}
};