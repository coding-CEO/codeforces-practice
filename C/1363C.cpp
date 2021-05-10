/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1363/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void dfs(auto &g, ll v, ll par, ll &ans, ll dep) {
    if(dep > 1) ans++;
    for(ll adj : g[v]) {
        if(adj == par) continue;
        dfs(g, adj, v, ans, dep+1);
    }
}

void runTest()
{
    ll n, x;
    cin >> n >> x;

    vector<vector<ll>> g(n+1);
    ll deg = 0;

    for(ll i=0; i<n-1; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        if(u == x || v == x) deg++;
    }

    if(deg <= 1) {
        cout << "Ayush" << endl;
        return;
    }

    ll removable = 0;
    dfs(g, x, 0, removable, 0);

    if((removable+deg)%2 == 0) {
        cout << "Ashish" << endl;
    }else {
        cout << "Ayush" << endl;
    }
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