class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+") {
                int num1, num2, result;
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                result = num1 + num2;
                st.push(result);
            }
            else if (token == "-") {
                int num1, num2, result;
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                result = num1 - num2;
                st.push(result);
            }
            else if (token == "*") {
                int num1, num2, result;
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                result = num1 * num2;
                st.push(result);
            }
            else if (token == "/") {
                int num1, num2, result;
                num2 = st.top();
                st.pop();
                num1 = st.top();
                st.pop();
                result = (int)(num1 / num2);
                st.push(result);
            }
            else {
                // number
                int num = 0;
                int isNeg = 1;
                for (char c : token) {
                    if (c == '-') {
                        isNeg = -1;
                        continue;
                    }
                    num *= 10;
                    num += (int)(c - '0') * isNeg;
                }
                st.push(num);
            }
        }
        return st.top();
    }
};
