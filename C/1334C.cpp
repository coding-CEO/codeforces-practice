/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1334/C
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

    ll a[n], b[n];
    for(ll i=0; i<n; i++) cin >> a[i] >> b[i];

    ll ans = 0;
    ll mini = 1e18;
    for(ll i=0; i<n; i++) {
        ll nextIndex = (i+1)%n;
        ll val = min(a[nextIndex], b[i]);
        ans += a[nextIndex] - val;
        mini = min(mini, val);
    }

    cout << ans + mini << endl;
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