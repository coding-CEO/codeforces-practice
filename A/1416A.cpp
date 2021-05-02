/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1416/A
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

    map<ll,vector<ll>> m;
    for(ll i=1; i<=n; i++) {
        ll val;
        cin >> val;
        if(m.find(val) == m.end()) m[val].push_back(0);
        m[val].push_back(i);
    }

    vector<ll> ans(n+1, INT_MAX);
    for(auto it : m) {
        ll maxGap = 0;
        for(ll i=1; i<it.second.size(); i++)
            maxGap = max(maxGap, it.second[i] - it.second[i-1] - 1);
        maxGap = max(maxGap, n - it.second[it.second.size()-1]);
        ans[maxGap+1] = min(ans[maxGap+1], it.first);
    }

    for(ll i=2; i<=n; i++) {
        ans[i] = min(ans[i], ans[i-1]);
    }

    for(ll i=1; i<=n; i++) {
        if(ans[i] == INT_MAX) cout << -1 << ' ';
        else cout << ans[i] << ' ';
    }
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}