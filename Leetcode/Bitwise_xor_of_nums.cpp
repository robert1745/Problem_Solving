#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        int v1 = 0;

        // if n1 is odd
        if (n1 % 2 != 0) {
            for (auto num : nums2) {
                v1 ^= num;
            }
        }
        if (n2 % 2 != 0) {
            for (auto num : nums1) {
                v1 ^= num;
            }
        }
        return v1;

        
    }
};