class Solution {
public:
    void backtrack(int open, int closed, int n, vector<string>& result, string& str) {
        if (open == closed && open == n) {
            result.push_back(str);
            return;
        }
        if (open < n) {
            str += '(';
            backtrack(open + 1, closed, n, result, str);
            str.pop_back();
        }
        if (closed < open) {
            str += ')';
            backtrack(open, closed + 1, n, result, str);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrack(0,0,n,res,str);
        return res;
    }
};
