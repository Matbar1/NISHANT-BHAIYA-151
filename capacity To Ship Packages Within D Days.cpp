class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        int days = 1;
        int curr = 0;

        for (int weight : weights) {
            if (curr + weight > mid) {
                days++;
                curr = 0;
            }
            curr += weight;
        }

        if (days > D)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}
};