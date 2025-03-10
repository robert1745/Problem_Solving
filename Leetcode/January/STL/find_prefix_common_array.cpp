#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
            int n = A.size();
            unordered_map<int, int> freq;
            vector<int> c(n, 0);
            int common = 0;
            for (int i = 0; i < n; i++) {
                if (++freq[A[i]] == 2)
                    common++;
                if (++freq[B[i]] == 2)
                    common++;
                c[i] = common;
            }
            return c;
        }
    };