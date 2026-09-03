class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push((char)1);
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            if (c == ')') {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (c == ']') {
                if (st.top() == '[')
                    st.pop();
                else 
                    return false;
            }
            else if (c == '}') {
                if (st.top() == '{')
                    st.pop();
                else {
                    return false;
                }
            }
        }
        if (st.size() > 1) return false;
        return true;
    }
};
