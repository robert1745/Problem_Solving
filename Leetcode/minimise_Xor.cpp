// 15 Jan 

/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

class Solution {

public:
    bool is_set(int& x, int bit) { return x & (1 << bit); }
    bool set_bit(int& x, int bit) { return x |= (1 << bit); }
    bool unset(int& x, int bit) { return x &= ~(1 << bit); }

public:
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int current_bits = __builtin_popcount(x);
        int req_setbit = __builtin_popcount(num2);
        int bit = 0; // we start with LSB
        if (current_bits < req_setbit) {
            while (current_bits < req_setbit) {
                if (!is_set(x, bit)) {
                    set_bit(x, bit);
                    current_bits++;
                }
                bit++;
            }
        } else if (current_bits > req_setbit) {
            while (current_bits > req_setbit) {
                if (is_set(x, bit)) {
                    unset(x, bit);
                    current_bits--;
                }
                bit++;
            }
        }
        return x;
    }
};


