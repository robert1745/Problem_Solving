/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

// Approach :

// we just need to ensure sum can't become prime
// how we will ensure that we create such permutation

// composite number :
//  All even nos > 2, same parity  number can become composite , see only one combination of 4+5
//  can make composite

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 2; i <= n; i += 2)
    {
        if (i != 4)
        {
            cout << i << " ";
        }
    }
    cout << "4 5 ";
    for (int i = 1; i <= n; i += 2)
    {
        if (i != 5)
        {
            cout << i << " ";
        }
    }
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
