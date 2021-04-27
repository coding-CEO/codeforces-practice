/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1299/A
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

    if(n == 1) {
        cout << a[0] << endl;
        return;
    }

    ll left[n], right[n];
    left[0] = (~a[0]);
    right[n-1] = (~a[n-1]);
    for(ll i=1; i<n; i++) {
        left[i] = (~a[i]) & left[i-1];
    }
    for(ll i=n-2; i>=0; i--) {
        right[i] = (~a[i]) & right[i+1];
    }

    ll ans = 0;
    ll ind = 0;
    for(ll i=0; i<n; i++) {
        if(i == 0) {
            ll val = a[i] & right[i+1];
            if(val > ans) {
                ans = val;
                ind = i;
            }
            continue;
        }
        if(i == n-1) {
            ll val = a[i] & left[i-1];
            if(val > ans) {
                ans = val;
                ind = i;
            }
            continue;
        }

        if(i-1 >= 0 && i+1 < n) {
            ll val = a[i] & left[i-1] & right[i+1];
            if(val > ans) ans = val, ind = i;
        }else if(i-1 >= 0) {
            ll val = a[i] & left[i-1];
            if(val > ans) ans = val, ind = i;
        }else {
            ll val = a[i] & right[i+1];
            if(val > ans) ans = val, ind = i;
        }
    }

    cout << a[ind] << ' ';
    for(ll i=0; i<n; i++) {
        if(i == ind) continue;
        cout << a[i] << ' ';
    }
    cout << endl;
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