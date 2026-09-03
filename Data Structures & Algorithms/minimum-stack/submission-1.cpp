class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        st = stack<int>();
        min_st= stack<int>();
    }
    
    void push(int val) {
        st.push(val);
        if (min_st.empty()) min_st.push(val);
        else if (val <= min_st.top()) min_st.push(val);
    }
    
    void pop() {
        if (st.empty()) return;
        int val = st.top();
        st.pop();
        if (!min_st.empty() && val == min_st.top()) min_st.pop();
    }
    
    int top() {
        if (!st.empty())
            return st.top();
        return 0;
    }
    
    int getMin() {
        if (!min_st.empty())
            return min_st.top();
        return 0;
    }
};
