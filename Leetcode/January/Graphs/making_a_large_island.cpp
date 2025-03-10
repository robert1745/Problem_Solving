#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Correct direction vectors
    
        int dfs(int i, int j, vector<vector<int>>& grid, int islandID, unordered_map<int, int>& islandSize) {
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;
            
            grid[i][j] = islandID; // Mark the island with its unique ID
            int size = 1;
            
            for (auto [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                size += dfs(ni, nj, grid, islandID, islandSize);
            }
            
            return size;
        }
        
        int largestIsland(vector<vector<int>>& grid) {
            n = grid.size();
            unordered_map<int, int> islandSize;
            int islandID = 2; // Start from 2 to avoid confusion with 0 and 1
            int maxIsland = 0;
            
            // Step 1: Mark all islands and store their sizes
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        int size = dfs(i, j, grid, islandID, islandSize);
                        islandSize[islandID++] = size;
                        maxIsland = max(maxIsland, size);
                    }
                }
            }
            
            // Step 2: Try converting each 0 to 1 and compute possible max island size
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        unordered_set<int> connectedIslands;
                        int newSize = 1; // Include the flipped 0
                        
                        for (auto [dx, dy] : directions) {
                            int ni = i + dx, nj = j + dy;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                                connectedIslands.insert(grid[ni][nj]);
                            }
                        }
                        
                        for (int id : connectedIslands) {
                            newSize += islandSize[id];
                        }
                        
                        maxIsland = max(maxIsland, newSize);
                    }
                }
            }
            
            return maxIsland;
        }
    };