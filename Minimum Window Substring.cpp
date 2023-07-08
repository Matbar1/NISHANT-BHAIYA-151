class Solution {
public:
    string minWindow(string s, string t) {vector<int> target(128, 0);
        for (char c : t) {
            target[c]++;
        }
        
        int required = t.length();
        int minLength = INT_MAX;
        int minStart = 0;
        int left = 0;
        int right = 0;
        
        while (right < s.length()) {
            if (target[s[right]] > 0) {
                required--;
            }
            target[s[right]]--;
            right++;
            
            while (required == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    minStart = left;
                }
                
                target[s[left]]++;
                if (target[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }
        
        return (minLength == INT_MAX) ? "" : s.substr(minStart, minLength);
    
        
    }
};