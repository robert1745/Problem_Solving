/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    ll m, a, b, c;
    cin >> m >> a >> b >> c;

    // Total seats are = 2*m
    // a wants to seat in first m
    // b wants to seat in second m
    // c dont have preference

    // m-a,m-b, remaining 2m-a-b < c
    // seats left in 1st row = |m - a|
    // seats left in 2nd row = |m - b|
    // Total seats = 2m, if 2m - a -b ==c then return 2m
    /*


    */

   
    ll row1_seats = min(m, a);
    ll row2_seats = min(m, b);
    ll row1_vacant = m - row1_seats;
    ll row2_vacant = m - row2_seats;

    ll remaining_seats = row1_vacant + row2_vacant;
    ll c_seats = min(c, remaining_seats);

    ll x = row1_seats + row2_seats + c_seats;
    cout << x << "\n";
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
