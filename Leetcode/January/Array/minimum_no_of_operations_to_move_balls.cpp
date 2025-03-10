#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n, 0);

        // approach-1 brute force
        // int cnt = 0;
        // for (int i = 0; i < n; i++) {
        //     if (boxes[i] == '1') {
        //         for (int j = 0; j < n; j++) {
        //             res[j] += abs(j - i);
        //         }
        //     }
        // }
        // return res;

        // approach-2 cumulative sum

        int cum_Sum = 0;
        int cum_Val = 0;

        for (int i = 0; i < n; i++) {

            res[i] += cum_Sum;
            cum_Val += (boxes[i] == '1' ? 1 : 0);
            cum_Sum += cum_Val;
        }

        cum_Sum = 0;
        cum_Val = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += cum_Sum;
            cum_Val += (boxes[i] == '1' ? 1 : 0);
            cum_Sum += cum_Val;
        }
        return res;
    }
};

/*

=> Dry run of brute force
 s = "110"
 i=0
    -> j=0 => [0,0,0]
    -> j=1 => [0,1,0]
    -> j=2 => [0,1,2]
 i=1
    -> j=0  => [1,1,2]
    -> j=1  => [1,1,2]
    -> j =2 => [1,1,3]

=> Dry run of optimised using cumulative sum
 => we have taken only 2 variables to solve the problem
   without taking an array and variable.

=> we first calculate from left side and then the right side by updating
  our cum_sum upto that idx and cum_val for that particular idx

*/
