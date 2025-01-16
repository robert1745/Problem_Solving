#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
    }
    else if (n == 2)
    {
        cout << "2\n";
    }
    else if (n == 3)
    {
        cout << "2\n";
    }
    else
    {
        int cnt = 2;
        int val = 4;
        while (val < n)
        {
            cnt += 1;
            val = 2 * (val + 1);
        }
        cout << cnt << "\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
