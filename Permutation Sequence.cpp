class Solution {
public:
    
string getPermutation(int n, int k) {
    string result;
    string nums = "";
    int factorial = 1;

    // Generate the initial sequence of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        nums += to_string(i);
        factorial *= i;
    }

    k--; // Convert k to zero-based index
    while (n > 0) {
        factorial /= n;
        int index = k / factorial;
        result += nums[index];
        nums.erase(nums.begin() + index);
        k %= factorial;
        n--;
    }

    return result;
}
};