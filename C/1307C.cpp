/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1307/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> occr(26, 0);
    vector<vector<ll>> dp(26, vector<ll>(26, 0));

    for(ll i=0; i<n; i++) {
        ll c = s[i] - 'a';
        for(ll j=0; j<26; j++)
            dp[j][c] += occr[j];
        occr[c]++;
    }

    ll ans = 0;
    for(auto it : dp){
        for(auto i : it) ans = max(ans, i);
    }
    for(auto it : occr) ans = max(ans, it);

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