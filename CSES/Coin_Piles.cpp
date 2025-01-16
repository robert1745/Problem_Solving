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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && (a <= 2 * b && b <= 2 * a))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
