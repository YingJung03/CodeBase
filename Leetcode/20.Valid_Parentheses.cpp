class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for (char c : s) {       // 跑字串裡的每個字
            if (c == '(' || c == '{' || c == '[') { 
                st.push(c); 
            } else { 
                if (st.empty() || 
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; 
                }else{
                    st.pop(); 
                }
            }
        }
        return true; 
    }
};    



