/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    ll cnt = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        cnt += (floor(n / i));
    }
    cout << cnt % mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    // cin>>test;
    // while (test--)
    // {
    solve();
    // }
    return 0;
}
