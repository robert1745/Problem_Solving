
/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

int solve1(string s)
{
    if (s.empty() || s[0] == '0')
    {
        return 0;
    }

    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] != '0')
        {
            dp[i] += dp[i - 1];
        }

        int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (num >= 10 && num <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    string s1;
    solve1(s1);

    return 0;
}
