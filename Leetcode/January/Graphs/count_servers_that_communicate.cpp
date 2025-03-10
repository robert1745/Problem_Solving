#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int i, int j,
                vector<vector<bool>>& visited, int& cnt) {
    
            int m = grid.size();
            int n = grid[0].size();
    
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 ||
                visited[i][j]) {
                return;
            }
    
            visited[i][j] = true;
            cnt++;
    
            for (int c = 0; c < n; c++) {
                if (grid[i][c] == 1 && !visited[i][c]) {
                    dfs(grid, i, c, visited, cnt);
                }
            }
    
            for (int r = 0; r < m; r++) {
                if (grid[r][j] == 1 && !visited[r][j]) {
                    dfs(grid, r, j, visited, cnt);
                }
            }
        }
        int countServers(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            int totalcount = 0;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
    
            // collecting all coordinates of 1s
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        int cnt = 0;
                        dfs(grid, i, j, visited, cnt);
                        if (cnt > 1)
                            totalcount += cnt;
                    }
                }
            }
            return totalcount;
        }
    };