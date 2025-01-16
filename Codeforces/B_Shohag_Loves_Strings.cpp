/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    // Approach : 
    /*

THOUGHT: The condition seems hard to track. So a good way is to play around with smaller cases
         and see if we can make some observations.

ACTION: Let's start with the smallest string. When s=a, the number of unique substrings f(s)=1
        ,so it's odd and not valid.

OBSERVATION: No one length strings are valid.

ACTION: Let's try the next smallest strings.

When s= aa, f(s)=2 , so it's even and valid.

When s=ab, f(s)=3, so it's odd and not valid.

OBSERVATION: Two length strings are valid if the adjacent characters are same.

THOUGHT: So if s contains two consecutive same characters, we can print it right away.
         All that remains is to consider strings without two consecutive same characters.

ACTION: Let's try the next smallest strings with adjacent different characters.

When s= aba, f(s)=5 , so it's odd and not valid.

When s= abc, f(s)=6 , so it's even and valid.

OBSERVATION: Three length strings are valid if all characters are different.

THOUGHT: So if s contains three consecutive different characters, we can print it right away.

All that remains is to consider strings without two adjacent same characters but no three consecutive
different characters.

So all the remaining strings are of the form s=
 abababababa...

Let's try to see if we can make some observations about these strings.

ACTION:Let's try to calculate the number of unique substrings for a string of the form s=abababababa...

There are exactly 2 unique substrings of length 1 : a and b.
There are exactly 2 unique substrings of length 2 : ab and ba.
There are exactly 2 unique substrings of length 3 : aba and bab.
…
There are exactly 2 unique substrings of length n−1.
However, the length n substring occurs exactly once.
OBSERVATION: The number of unique substrings of any length is 2. But only the length n
 substring occurs exactly once. So total number of unique substrings is 2n−1
. And this is always odd! So there is no solution for these strings.

THOUGHT: We have covered all the cases.

CONCLUSION: If there are adjacent same characters, we can print it right away.
            If there are three consecutive different characters, we can print it right away.
            Otherwise there is no solution.

Time Complexity: O(n)
.



    */

    string s;
    cin >> s;
    int n = s.size();

    // string consists of same adjacent characters.
    for (int i = 0; i + 1 < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            cout << s.substr(i, 2) << '\n';
            return;
        }
    }

    for (int i = 0; i + 2 < n; i++)
    {
        if ( s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
        {
            cout << s.substr(i, 3) << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test ;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
