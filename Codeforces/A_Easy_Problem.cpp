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
    int cnt =0;
    // we need to find factors of n
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }
    cout<<n-1<<"\n";

    /*
       a+b = 1 -> 0
       a+b = 2 -> 1
       a+b  =3 -> 2
       a+b=4 ->   3
       a+b =5 ->  4
       a+b =6 ->  5
    
    */
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
