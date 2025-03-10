#include<bits/stdc++.h>
using namespace std;


// Approach which doesn't work
// This approach will cause problem in ordering or handling the
// duplicate values as in map it is always overwritten by next greater
// element

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
    
            vector<int> newarr(nums.begin(), nums.end()); 
            newarr.insert(newarr.end(), nums.begin(), nums.end());
    
            unordered_map<int,int>nge;
            int n = nums.size();
            vector<int>res(n,-1);
            stack<int>st;
    
            for(auto it : newarr){
                while(!st.empty() && st.top()< it ){
                    nge[st.top()] = it;
                    st.pop();
                }
                st.push(it);
            }
    
            for(int i=0;i<n;i++){
                if(nge.find(nums[i])!=nge.end()){
                    res[i] = nge[nums[i]];
                }
            }
            return res;
        }
    };


// Optimized approach using stack
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, -1);
            stack<int> st;
    
            for (int i = 0; i < 2 * n; i++) {
                while (!st.empty() && nums[st.top()] < nums[i % n]) {
                    res[st.top()] = nums[i % n];
                    st.pop();
                }
                if (i < n)
                    st.push(i);
            }
    
            return res;
        }
    };