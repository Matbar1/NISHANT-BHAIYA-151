class Solution {
public:
   
bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> closingBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (closingBrackets.count(c)) {
            if (stk.empty() || stk.top() != closingBrackets[c]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    return stk.empty();
}
};