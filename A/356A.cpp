/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/356/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m;
    cin >> n >> m;

    set<ll> se;
    vector<ll> ans(n+1, 0);

    for(ll i=1; i<=n; i++) se.insert(i);

    for(ll i=0; i<m; i++) {
        ll l, r, w;
        cin >> l >> r >> w;

        auto it = se.lower_bound(l);
        while(it != se.end()) {
            if(*it > r) break;
            if(*it == w) {
                it = next(it);
                continue;
            }
            ans[*it] = w;
            auto temp = it;
            it = next(it);
            se.erase(temp);
        }
    }

    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
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