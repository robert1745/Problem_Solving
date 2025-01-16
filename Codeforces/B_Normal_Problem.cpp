/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    string a;
    cin>>a;

    // we just need to mirror it 
    // qwq -> pwp or we can say 
    // wqpqwpqwwqp --> reverse kr iss string ko -> pqwwqpwqpqw -> now change p to q , q to p
    // qpwwpqwpqpw

    // pwp
    string temp = a;
    string res = "";
    for(int i=temp.length();i>=0;i--){
        if(temp[i]=='p') res+='q';
        else if(temp[i]=='q') res+='p';
        else if(temp[i]=='w') res+=temp[i];
    }
    cout<<res<<"\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = 1;
    cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
