/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1389/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, k, z;
    cin >> n >> k >> z;

    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    ll ans = 0;

    for(ll i=0; i<=z; i++) {
        ll pos = k - 2*i;

        if(pos < 0) continue;

        ll mx = 0, s = 0;

        for(ll j=0; j<=pos; j++) {
            if(j+1 < n)
                mx = max(mx, a[j] + a[j+1]);
            s += a[j];
        }

        ans = max(ans, s + mx*i);
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