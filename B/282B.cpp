/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/584/B
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
    for(ll i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    string ans = "";
    ll A = 0, G = 0;
    for(ll i=0; i<n; i++) {
        ll val = abs(A+a[i].first-G);
        if(val <= 500) {
            ans += 'A';
            A += a[i].first;
            continue;
        }
        val = abs(G+a[i].second - A);
        if(val <= 500) {
            ans += 'G';
            G += a[i].second;
            continue;
        }

        cout << "-1" << endl;
        return;
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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}