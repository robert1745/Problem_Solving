class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.length();
        unordered_set<char> letter;
        for (int i = 0; i < n; i++) {
            letter.insert(s[i]);
        }

        int res = 0;
        for (char x : letter) {
            int left_idx = -1, right_idx = -1;

            for (int i = 0; i < n; i++) {
                if (s[i] == x) {
                    if (left_idx == -1) {
                        left_idx = i;
                    }
                    right_idx = i;
                }
            }

            unordered_set<char> st1;
            for (int k = left_idx + 1; k <= right_idx - 1; k++) {
                st1.insert(s[k]);
            }

            res += st1.size();
        }
        return res;
    }
};
