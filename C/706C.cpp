/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/706/C
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

    ll c[n];
    for(ll i=0; i<n; i++) cin >> c[i];

    pair<string, string> a[n];
    for(ll i=0; i<n; i++) {
        string temp;
        cin >> temp;
        a[i].first = temp;
        reverse(temp.begin(), temp.end());
        a[i].second = temp;
    }

    vector<pair<ll, ll>> dp(n);
    dp[0] = {0, c[0]};

    for(ll i=1; i<n; i++) {
        ll first = 1e18;
        if(a[i].first >= a[i-1].first) first = min(first, dp[i-1].first);
        if(a[i].first >= a[i-1].second) first = min(first, dp[i-1].second);
        dp[i].first = first;

        ll second = 1e18;
        if(a[i].second >= a[i-1].first) second = min(second, dp[i-1].first);
        if(a[i].second >= a[i-1].second) second = min(second, dp[i-1].second);

        if(second != 1e18)
            dp[i].second = second+c[i];
        else
            dp[i].second = second;
    }

    ll ans = min(dp[n-1].first, dp[n-1].second);
    if(ans != 1e18)
        cout << ans << endl;
    else 
        cout << -1 << endl;
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