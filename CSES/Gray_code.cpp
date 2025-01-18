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
    int totalnumbers = 1 << n; // 2^n
    vector<string> ans;

    // it will generate all binary string for length n but it will generate any solution
    // we want to print only differ by 1 digit
    // for (int i = 0; i < totalnumbers; i++)
    // {
    //     string res = "";
    //     for (int j = n - 1; j >= 0; j--)
    //     {
    //         res += ('0' + ((i >> j) & 1)) ; // Extract each bit
    //     }
    //     ans.push_back(res);
    // }
    for (int i = 0; i < totalnumbers; i++)
    {
        int grey = i ^ (i >> 1);
        string res = "";
        for (int j = n - 1; j >= 0; j--)
        {
            res += (grey & (1 << j)) ? '1' : '0'; 
        }
        ans.push_back(res);
    }

    for (auto it : ans)
    {
        cout << it << "\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    // cin>>test;
    solve();

    return 0;
}
