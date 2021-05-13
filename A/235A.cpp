/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/235/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll lcm(ll a, ll b) {
    return (a*b)/(__gcd(a, b));
}

void runTest()
{
    ll n;
    cin >> n;

    if(n <= 2) {
        cout << n << endl;
        return;
    }

    ll st = max(1LL, n-50);
    ll ans = 0;

    for(ll i=st; i<=n; i++) 
        for(ll j=st; j<=n; j++)
            for(ll k=st; k<=n; k++)
                ans = max(ans, lcm(lcm(i, j), k));

    cout << ans << endl;
}

int main()
{

#if !defined(ONLINE_JUDGE)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}