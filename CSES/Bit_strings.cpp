/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// T.c = log(n) , pow fxn takes 2^n time so it will not pass for n=10^6

ll modular_exponentiation(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod; // Multiply if exp is odd
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

void solve()
{
    int n;
    cin >> n;
    cout << modular_exponentiation(2, n) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
