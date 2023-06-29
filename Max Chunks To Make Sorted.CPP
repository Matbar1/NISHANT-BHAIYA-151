class Solution {
public:
    
int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0;
    int max_val = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        max_val = max(max_val, arr[i]);
        
        // If the maximum value encountered so far is equal to the current index,
        // it means all elements from 0 to max_val are in the correct positions,
        // so we can form a new chunk.
        if (max_val == i) {
            chunks++;
        }
    }
    
    return chunks;

        
    }
};