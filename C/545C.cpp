/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/545/C
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

    pair<ll,ll> a[n];
    ll pre = INT_MIN;
    ll ans = 0;

    for(ll i=0; i<n; i++) {
        ll x, h;
        cin >> x >> h;
        a[i] = {x, h};
    }

    for(ll i=0; i<n-1; i++) {
        ll x = a[i].first;
        ll h = a[i].second;
        if(x-h > pre) {
            ans++;
            pre = x;
        }else if(x+h < a[i+1].first) {
            ans++;
            pre = x+h;
        }else {
            pre = x;
        }
    }

    cout << ans + 1 << endl;
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