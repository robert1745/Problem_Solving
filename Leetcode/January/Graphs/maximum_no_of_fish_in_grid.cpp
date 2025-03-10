#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, int& cnt, vector<vector<bool>>& visited,
              vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // base case handling
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        cnt += grid[i][j];

        // exploring the directions
        for (auto& dir : directions) {
            int new_X = i + dir.first;
            int new_Y = j + dir.second;
            dfs(new_X, new_Y, cnt, visited, grid);
        }
        return cnt;
    }
    int bfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    int cnt = 0; // Fish count for this connected component

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Collect fish at the current cell
        cnt += grid[x][y];

        // Explore neighbors
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] > 0) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return cnt; // Return the total fish collected
}

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxcnt = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxcnt = max(maxcnt, bfs(i, j, visited, grid));
                }
            }
        }
        return maxcnt;
    }
};