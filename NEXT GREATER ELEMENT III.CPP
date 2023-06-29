class Solution {
public:
    int nextGreaterElement(int n) {
           string str = to_string(n);
    int len = str.length();
    
    // Find the first decreasing digit from the right
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    
    if (i < 0) {
        // If there is no decreasing digit, it is not possible to form a greater number
        return -1;
    }
    
    // Find the smallest digit greater than str[i] to the right of str[i]
    int j = len - 1;
    while (j > i && str[j] <= str[i]) {
        j--;
    }
    
    // Swap the digits at positions i and j
    swap(str[i], str[j]);
    
    // Reverse the substring from i + 1 to the end
    reverse(str.begin() + i + 1, str.end());
    
    long long next = stoll(str);
    
    // Check for integer overflow
    return (next > INT_MAX) ? -1 : next;

        
    }
};