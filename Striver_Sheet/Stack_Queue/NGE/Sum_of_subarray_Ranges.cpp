#include<bits/stdc++.h>
using namespace std;
// This is brute force approach 
// Time = O(n^2) we are finding running max , min for each subarray and adding to the sum 
// opimisation : we can avoid counting max, min for each subarray like we can see 
// which element is contributing to how many max, min => Monotonic stack decreasing , increasing
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int min_val = nums[i],max_val = nums[i];
            for (int j = i; j < n; j++) {
                min_val = min(min_val,nums[j]);
                max_val = max(max_val,nums[j]);
                res+=(max_val-min_val);
            }
        }
        return res;
    }
};



// Optimised solution using stack
class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            
            // Catch here in optimisation are :
            // we have created an extra dummy index i == n for handle all elements
    
            // for max contribution we have used monotonic decreasing stack
            // for min contribution we have used monotonic increasing stack
            
    
            int n = nums.size();
            long long sum_max = 0, sum_min = 0;
            stack<int> st;
    
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                    int idx = st.top();
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    sum_max += (long long)nums[idx] * (idx - left) * (i - idx);
                }
                st.push(i);
            }
    
            while (!st.empty())
                st.pop();
    
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                    int idx = st.top();
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    sum_min += (long long)nums[idx] * (idx - left) * (i - idx);
                }
                st.push(i);
            }
            return sum_max - sum_min;
        }
    };

