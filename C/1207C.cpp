/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1207/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007
#define inf __LONG_LONG_MAX__/100

using namespace std;

void runTest()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector<pair<ll,ll>> dp(n, {a+b, inf});
    for(ll i=1; i<n; i++) {
        if(s[i] == '0') {
            dp[i].first = min(dp[i-1].first + a + b, dp[i-1].second + 2*(a+b));
            dp[i].second = min(dp[i-1].first + 2*(a + b), dp[i-1].second + a + 2*b);
        }else {
            dp[i].first = inf;
            dp[i].second = min(dp[i-1].first + 2*(a + b), dp[i-1].second + a + 2*b);
        }
    }

    cout << dp[n-1].first + b << endl;
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