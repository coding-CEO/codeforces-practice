/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1196/D1
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll pre[3][n+1];
    pre[0][0] = 0;
    pre[1][0] = 0;
    pre[2][0] = 0;

    for(ll j=0; j<n; j++) {
        char c;
        if(j%3 == 0) c = 'R';
        else if(j%3 == 1) c = 'G';
        else if(j%3 == 2) c = 'B';
        pre[0][j+1] = pre[0][j] + (s[j] != c);
    }
    for(ll j=0; j<n; j++) {
        char c;
        if(j%3 == 0) c = 'G';
        else if(j%3 == 1) c = 'B';
        else if(j%3 == 2) c = 'R';
        pre[1][j+1] = pre[1][j] + (s[j] != c);
    }
    for(ll j=0; j<n; j++) {
        char c;
        if(j%3 == 0) c = 'B';
        else if(j%3 == 1) c = 'R';
        else if(j%3 == 2) c = 'G';
        pre[2][j+1] = pre[2][j] + (s[j] != c);
    }

    ll ans = INT_MAX;
    for(ll i=k; i<=n; i++) {
        for(ll j=0; j<3; j++)
            ans = min(ans, pre[j][i] - pre[j][i-k]);
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