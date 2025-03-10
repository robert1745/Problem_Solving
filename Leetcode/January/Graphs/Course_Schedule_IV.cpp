#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool dfs(unordered_map<int, vector<int>>& mp, int src, int dest, vector<bool>& visited) {
            visited[src] = true; // mark it as visited
            if (src == dest) {
                return true; // we can reach the dest from src
            }
            bool flag = false; // reachable or not
            for (auto& adjnode : mp[src]) {
                if (!visited[adjnode]) {
                    flag = flag || dfs(mp, adjnode, dest, visited);
                }
            }
            return flag;
        }
    
        bool bfs(unordered_map<int, vector<int>>& mp, int src, int dest, int numCourses) {
            if (src == dest)
                return true;
    
            queue<int> q;
            vector<bool> visited(numCourses, false); // Fix: Use numCourses
            q.push(src);
            visited[src] = true;
    
            while (!q.empty()) {
                int u = q.front();
                q.pop();
    
                for (auto it : mp[u]) {
                    if (it == dest) {
                        return true;
                    }
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
            return false;
        }
    
        vector<bool> checkIfPrerequisite(int numCourses,
                                          vector<vector<int>>& prerequisites,
                                          vector<vector<int>>& queries) {
            int n = numCourses;
            unordered_map<int, vector<int>> mp;
    
            for (auto& it : prerequisites) {
                mp[it[0]].push_back(it[1]);
            }
    
            int q = queries.size();
            vector<bool> ans(q, false);
            for (int i = 0; i < q; i++) {
                int u = queries[i][0];
                int v = queries[i][1];
                ans[i] = bfs(mp, u, v, numCourses); 
            }
    
            return ans;
        }
    };