class Solution {
public:
    int divide(int dividend, int divisor) {
    // Handle overflow cases
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    // Determine the sign of the quotient
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    // Convert both dividend and divisor to positive
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);

    // Initialize the quotient and remainder
    long long quotient = 0;
    long long remainder = 0;

    // Perform division
    for (int i = 31; i >= 0; --i) {
        if ((absDividend >> i) >= absDivisor) {
            quotient |= 1LL << i;
            absDividend -= absDivisor << i;
        }
    }

    // Apply the sign to the quotient
    quotient *= sign;

    // Handle overflow case
    if (quotient > INT_MAX) {
        return INT_MAX;
    }

    return static_cast<int>(quotient);
}
};