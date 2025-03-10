#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // bool checkRowPainted(vector<vector<int>>& mat, int row) {
        //     for (int col = 0; col < mat[0].size(); col++) {
        //         if (mat[row][col] > 0) { // not painted
        //             return false;
        //         }
        //     }
    
        //     return true;
        // }
    
        // bool checkColPainted(vector<vector<int>>& mat, int col) {
        //     for (int row = 0; row < mat.size(); row++) {
        //         if (mat[row][col] > 0) { // not painted
        //             return false;
        //         }
        //     }
    
        //     return true;
        // }
        int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    
            int m = mat.size();
            int n = mat[0].size();
    
            unordered_map<int, int> mp;
    
            for (int i = 0; i < arr.size(); i++) {
                int val = arr[i];
                mp[val] = i;
            }
    
            int min_idx = INT_MAX;
    
            for (int r = 0; r < m; r++) {
                int last_idx = INT_MIN;
                for (int c = 0; c < n; c++) {
                    int val = mat[r][c];
                    int idx = mp[val];
                    last_idx = max(last_idx, idx);
                }
                min_idx = min(last_idx, min_idx);
            }
    
            for (int c = 0; c < n; c++) {
                int last_idx = INT_MIN;
                for (int r = 0; r < m; r++) {
                    int val = mat[r][c];
                    int idx = mp[val];
                    last_idx = max(last_idx, idx);
                }
                min_idx = min(last_idx, min_idx);
            }
            return min_idx;
        }
    };