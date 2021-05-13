/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1349/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n;
    cin >> n;

    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    ll pre[n]; // Technically it is suffix
    pre[n-1] = a[n-1];

    ll ele = a[n-1];
    for(ll i=n-2; i>=0; i--) {
        ele = __gcd(ele, a[i]);
        pre[i] = ele;
    }

    ll ans = (pre[n-1]*a[n-2]) / pre[n-2];
    for(ll i=0; i<n-2; i++) {
        ans = __gcd(ans, (a[i]*pre[i+1])/pre[i]);
    }

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