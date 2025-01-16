/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a.insert(a.begin(), 0);
    a.push_back(x); 
    // sort(a.begin(), a.end());

   
    int maxDist = 0;
    for (int i = 1; i < a.size(); i++)
    {
        maxDist = max(maxDist, a[i] - a[i - 1]);
    }

    maxDist = max(maxDist, 2 * (x - a[a.size() - 2]));
    cout << maxDist << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
