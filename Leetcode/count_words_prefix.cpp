
/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string &s1 = words[i];
            if (s1.find(pref) == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}
