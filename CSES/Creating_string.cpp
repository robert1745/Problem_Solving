/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve(int idx, string &s, set<string> &ans)
{

    if (idx == s.size())
    {
        ans.insert(s);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        if (i != idx && s[i] == s[idx])
            continue;
        swap(s[idx], s[i]);
        solve(idx + 1, s, ans);
        swap(s[idx], s[i]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    set<string> res;
    solve(0, s, res);
    cout << res.size() << "\n";
    for (auto it : res)
    {
        cout << it << "\n";
    }

    return 0;
}
