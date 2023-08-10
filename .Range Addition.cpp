class Solution {
public:
vector<int> getModifiedArray(int length, std::vector<std::vector<int>>& updates) {
    std::vector<int> result(length, 0);

    for (const auto& update : updates) {
        int startIndex = update[0];
        int endIndex = update[1];
        int inc = update[2];

        result[startIndex] += inc;
        if (endIndex + 1 < length) {
            result[endIndex + 1] -= inc;
        }
    }

    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += result[i];
        result[i] = sum;
    }

    return result;
}