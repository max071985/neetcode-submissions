class Solution {
public:
    string minWindow(string s, string t) {
        /* Idea: 
        maintain a hashmap with t's occurance counter
        slide a window and fill a window occurances hashmap - 
        when a character gets the same occurance count as in t, increment a counter
        when the counter reaches the total characters in t, then 
            the window contains a substring of t.
        always store the minimal substring
        */ 

        if (t.size() > s.size()) return "";
        unordered_map<char, int> t_occurances;
        unordered_map<char, int> window_occurances;
        int t_unique_char = 0, window_matching_chars = 0;

        // Add the character frequency to the hashmap of t
        // Count how many unique characters t has
        for (char c : t) {
            t_occurances[c]++;
            if (t_occurances[c] == 1) t_unique_char++;
        }

        int l = 0, r = 0;
        int N = s.size() - 1;
        int minL = -1, minR = s.size();
        // Iterate over s in a sliding window
        // Edge case for 1st elem
        window_occurances[s[0]]++;
        if (window_occurances[s[0]] == t_occurances[s[0]]) {
            window_matching_chars++;
        }
        while (l <= N) {
            // If the window contains a full substring:
            if (window_matching_chars == t_unique_char) {
                int last_string_sz = minR - minL + 1;
                int curr_string_sz = r - l + 1;
                // If a new shortest substring is found, update output
                if (curr_string_sz < last_string_sz) {
                    minL = l;
                    minR = r;
                }
                // Now shrink the left side.
                // Decrement the occurance of the left index character in the counter map
                window_occurances[s[l]]--;
                // Check if a valid substring is still within the window
                if (window_occurances[s[l]] < t_occurances[s[l]]) {
                    // if its not - decrement the valid character counter
                    window_matching_chars--;
                }

                l++;
            }
            // Otherwise, the window doesn't contain a full substring
            else {
                // Increment to the right
                if (r == N) {
                    // Nowhere to increment -> no possible substrings
                    break;
                }
                r++;
                window_occurances[s[r]]++;
                // if the new index character occurances within the window match the substring occurances
                // increment the counter for the letter
                if (window_occurances[s[r]] == t_occurances[s[r]]) {
                    window_matching_chars++;
                }
            }
        }
        if (minL != -1)
            return s.substr(minL, minR - minL + 1);
        return "";
    }
};
