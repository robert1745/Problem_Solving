/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

// Approach -1
/*

1. WE try to build the array by using property , x^y =z or y^z =x
2. we atlast check for the last index if it is matching or not if yes => T else false

*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        vector<int>original(n);
        original[0]=0;
        for(int i=0;i<n-1;i++){
            original[i+1] = original[i]^derived[i];
        }
        if(original[n-1]^original[0]==derived[n-1]){
            return true;
        }

        original[0]=1;
        for(int i=0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }
        if(original[n-1]^original[0]==derived[n-1]){
            return true;
        }

        return false;
    }
};

/*





*/

