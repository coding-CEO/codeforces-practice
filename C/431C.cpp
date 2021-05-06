/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/431/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll memo[100+1][2];

ll fun(ll sum, ll dbig, ll n, ll k, ll d) {
    if(sum > n) return 0;
    if(sum == n) {
        if(dbig) return 1;
        return 0;
    }

    if(memo[sum][dbig] != -1) {
        return memo[sum][dbig];
    }

    ll ans = 0;

    for(ll i=1; i<=k; i++) {
        ll ndbig = dbig | (ll)(i>=d);
        ans = (ans + fun(sum+i, ndbig, n, k, d))%mod;
    }

    return memo[sum][dbig] = ans;
}

void runTest()
{
    ll n, k, d;
    cin >> n >> k >> d;

    memset(memo, -1, sizeof(memo));

    cout << fun(0, 0, n, k, d) << endl;
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