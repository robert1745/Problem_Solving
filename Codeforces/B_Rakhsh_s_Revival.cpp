/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()


// Intitution

/*

Task : we want to make string s strengthen with teh help of timbar effects 
      What he can do?
      -> He make k segment to be 1 from 0 
      what is sign of weak -> If string is having 0, we want to avoid m contiguos zeroes

    1. we make use of prefix sum approach with differnce array to track timbar ability
    2. we are using sum as running to tell which positions are strengthend
    3. a[n] = differnce array to track timbar operations
    4. cnt = counting the consecutive weak spots

*/


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        string s;
        cin >> s;
        vector<int>a(n,0);
        int cnt = 0, sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {  
            sum += a[i];
            if (sum || s[i] == '1')
            {
                cnt = 0;
            }
            else
            {   
                cnt++;
                if (cnt == m)
                {   
                    ans++, cnt = 0, sum++;
                    if(i+k<n) a[i+k]--;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
