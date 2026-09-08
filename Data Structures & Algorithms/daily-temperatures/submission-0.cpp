class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
            Brute force solution:
                for each i in [0, N], do:
                    for each j in (i, N] do:
                        if temperatures[j] > temperatures[i]
                            result[i] = j - i
                            break
            // This solution's time complexity is O(n^2). which can be improved.

            We need to know if there are any elements that satisfy:
            let i be some index.
            1. i < j <= N.
            2. temperatures[i] < temperatures[j]
            3. if index k_i satisfies 1 + 2, then j = min(k_i).

            Idea:
            for <temp, idx> in temperatures:
                pop all <temp2,idx2> pairs in the stack that satisfy:
                    temp2 < temp
                    result[idx2] = idx - idx2
                push <temp,idx> into the stack
            for <temp, idx> in stack
                result[idx] = 0
        */

        stack<pair<int, int>> st;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            pair<int, int> currPair = {temperatures[i], i};
            while(!st.empty()) {
                if (st.top().first < currPair.first) {
                    pair<int, int> foundMatch = st.top();
                    st.pop();
                    result[foundMatch.second] = currPair.second - foundMatch.second;
                }
                else {
                    break;
                }
            }
            // Add new pair
            st.push(currPair);
        }
        while(!st.empty()) {
            pair<int, int> remainder = st.top();
            st.pop();
            result[remainder.second] = 0;
        }
        return result;
    }
};
