/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1141/C
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
    ll mini = 1;
    ll ind = 0;
    ll a[n-1];
    ll sum = 0;
    for(ll i=0; i<n-1; i++) {
        cin >> a[i];
        sum += a[i];
        if(sum < mini) {
            mini = sum;
            ind = i+1;
        }
    }

    ll ans[n];
    unordered_set<ll> se;
    ans[ind] = 1;
    se.insert(1);
    for(ll i=ind; i<n-1; i++) {
        ans[i+1] = ans[i] + a[i];
        if(ans[i+1] > n || se.find(ans[i+1]) != se.end()) {
            cout << -1 << endl;
            return;
        }
        se.insert(ans[i+1]);
    }
    for(ll i=ind-1; i>=0; i--) {
        ans[i] = ans[i+1] - a[i];
        if(ans[i] > n || se.find(ans[i]) != se.end()) {
            cout << -1 << endl;
            return;
        }
        se.insert(ans[i]);
    }

    for(ll i=0; i<n; i++) cout << ans[i] << ' ';
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