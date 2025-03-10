#include <bits/stdc++.h>
using namespace std;
// Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/

// Brute force approach 
// Time complexity = O(m*n) , space = O(m) due to hash map + O(n) due to output vector
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            int m = nums2.size();
    
            vector<int> res(n, -1); 
    
            unordered_map<int, int> mp;
            for (int i = 0; i < m; i++) {
                mp[nums2[i]] = i;  
            }
    
            for (int j = 0; j < n; j++) {  
                int it = nums1[j];
                if (mp.find(it) != mp.end()) {
                    int idx = mp[it];
                    for (int i = idx + 1; i < m; i++) {
                        if (nums2[i] > it) {
                            res[j] = nums2[i];  // Assign instead of push_back
                            break;  // Stop at first greater element
                        }
                    }
                }
            }
            return res;
        }
    };


// Optimized approach using stack
// Time complexity = O(m+n) , space = O(m) due to hash map + O(n) due to output vector

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
            // Stack Solution with O(m)
            int n = nums1.size();
            vector<int> res(n, -1);
            unordered_map<int, int> nge;
            stack<int> st;
    
            // building stack
            for (auto num : nums2) {
                while (!st.empty() && st.top() <num) {
                    nge[st.top()] = num;
                    st.pop();
                }
                st.push(num);
            }
            // filling the res vector
    
            for(int i=0;i<n;i++){
                if(nge.find(nums1[i])!=nge.end()){
                    res[i] = nge[nums1[i]];
                }
            }
            return res;
        }
    };