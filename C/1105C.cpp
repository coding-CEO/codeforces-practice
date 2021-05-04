/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1105/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, l, r;
    cin >> n >> l >> r;

    ll cou[3] = {0};
    cou[l%3] = 1 + ((r-l)/3);
    if(l+1 <= r) cou[(l%3 + 1)%3] = 1 + ((r-l-1)/3);
    if(l+2 <= r) cou[(l%3 + 2)%3] = 1 + ((r-l-2)/3);

    // cout << cou[0] << ' ' << cou[1] << ' ' << cou[2] << endl;

    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[0][0] = 1;
    for(ll i=1; i<=n; i++) {
        dp[i][0] = (dp[i][0] + dp[i-1][0]*cou[0])%mod;
        dp[i][0] = (dp[i][0] + dp[i-1][1]*cou[2])%mod;
        dp[i][0] = (dp[i][0] + dp[i-1][2]*cou[1])%mod;

        //////////// I know it is bad code 

        dp[i][1] = (dp[i][1] + dp[i-1][0]*cou[1])%mod;
        dp[i][1] = (dp[i][1] + dp[i-1][1]*cou[0])%mod;
        dp[i][1] = (dp[i][1] + dp[i-1][2]*cou[2])%mod;

        //////////// I know it is bad code 

        dp[i][2] = (dp[i][2] + dp[i-1][0]*cou[2])%mod;
        dp[i][2] = (dp[i][2] + dp[i-1][1]*cou[1])%mod;
        dp[i][2] = (dp[i][2] + dp[i-1][2]*cou[0])%mod;
    }
    
    cout << dp[n][0] << endl;
    // for(ll i=0; i<=n; i++) cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
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