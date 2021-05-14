/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/446/A
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

    if(n <= 2) { 
        cout << n << endl;
        return;
    }

    ll left[n];
    ll right[n];
    left[0] = 1;
    right[n-1] = 1;
    for(ll i=1; i<n; i++) {
        if(a[i] > a[i-1])
            left[i] = 1 + left[i-1];
        else
            left[i] = 1;
    }
    for(ll i=n-2; i>=0; i--) {
        if(a[i] < a[i+1])
            right[i] = 1 + right[i+1];
        else
            right[i] = 1;
    }

    ll ans = 0;
    for(ll i=0; i<n; i++) {
        if(i == 0) {
            if(i+1 < n)
                ans = max(ans, right[i+1]+1);
            else
                ans = max(ans, 1LL);
            continue;
        }
        if(i == n-1) {
            if(i-1 >= 0)
                ans = max(ans, left[i-1]+1);
            else
                ans = max(ans, 1LL);
            continue;
        }
        if(a[i-1]+1 < a[i+1])
            ans = max(ans, left[i-1] + right[i+1] + 1);

        ans = max(ans, right[i+1]+1);
        ans = max(ans, left[i-1]+1);
    }

    cout << ans << endl;
}

int main()
{

#if !defined(ONLINE_JUDGE)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}