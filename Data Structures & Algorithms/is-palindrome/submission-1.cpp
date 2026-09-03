class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char left = tolower(s[l]);
            char right = tolower(s[r]);
            bool flag = false;
            if ((left < 'a' || left > 'z') && !isdigit(left)) {
                l++;
                flag = true;
            }
            if ((right < 'a' || right > 'z') && !isdigit(right)) {
                r--;
                flag = true;
            }
            if (!flag) {
                if (left != right)  
                    return false;
                l++;
                r--;
            }
        }
        return true;
    }
};
