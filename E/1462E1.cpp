/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1462/E1
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll nc2(ll n) {
    if(n <= 1) return 0;
    return (n*(n-1))/2;
}

void runTest()
{
    ll n;
    cin >> n;

    ll a[n+3] = {0};
    ll ans = 0;
    for(ll i=0; i<n; i++) {
        ll val;
        cin >> val;
        
        ans += a[val-1]*a[val];
        ans += nc2(a[val-1]);
        if(val-2 >= 0) {
            ans += nc2(a[val-2]);
            ans += a[val-2] * a[val-1];
            ans += a[val-2] * a[val];
        }

        ans += a[val-1] * a[val+1];

        ans += a[val+1]*a[val+2];
        ans += a[val]*a[val+1];
        ans += a[val]*a[val+2];
        ans += nc2(a[val+2]);
        ans += nc2(a[val+1]);

        ans += nc2(a[val]);

        a[val]++;
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}