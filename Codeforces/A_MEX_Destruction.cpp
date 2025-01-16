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
        cin >> a[i];
    }

    // if we dont include the border 0s on both side then answer will be 1
    // if all elements are 0 -> 0
    // if 0 present in betweeen then answer will be 2

    // set<int> st;
    // int cnt = 0;
    // while (true)
    // {
    //     int start = -1;
    //     for (int i = 0; i < n-1; i++)
    //     {

    //         if (a[i] != 0 )
    //         {
    //             start = i;
    //             break;
    //         }
    //     }

    //     if (start == -1)
    //         break;

    //     int end = start;
    //     while (end < n && a[end] != 0)
    //     {
    //         st.insert(a[end]);
    //         end++;
    //     }

    //     // calculation of mex
    //     int mex = 0;
    //     while (st.count(mex))
    //         mex++;

    //     for (int i = start; i < end; i++)
    //     {
    //         a[i] = mex;
    //     }
    //     cnt++;
    // }
    int cnt = 0;
    bool flag = false;
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    reverse(a.begin(), a.end());

    if (a.empty())
    {
        cout << 0 << '\n';
        return;
    }

    for (const auto x : a)

        flag |= (x == 0);
    if (flag)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
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
