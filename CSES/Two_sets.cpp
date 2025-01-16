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
    ll sum = (1ll) * n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    ll target = sum / 2;

    vector<int> v1, v2;

    for (int i = n; i >= 1; i--)
    {
        if (target >= i)
        {
            v1.push_back(i);
            target -= i;
        }
        else
        {
            v2.push_back(i);
        }
    }

    cout << v1.size() << '\n';
    for (auto x : v1)
        cout << x << " ";
    cout << '\n';
    cout << v2.size() << '\n';
    for (auto x : v2)
        cout << x << " ";
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
