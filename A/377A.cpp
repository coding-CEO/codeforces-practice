/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/377/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void dfs(auto &g, ll i, ll j, ll n, ll m, ll k, auto &vis, auto &dep, ll dept) {
    vis.insert({i, j});
    dep.push_back({dept, {i, j}});

    if(i+1 < n && g[i+1][j] == '.' && vis.find({i+1, j}) == vis.end()) {
        dfs(g, i+1, j, n, m, k, vis, dep, dept+1);
    }

    if(j+1 < m && g[i][j+1] == '.' && vis.find({i, j+1}) == vis.end()) {
        dfs(g, i, j+1, n, m, k, vis, dep, dept+1);
    }

    if(i-1 >= 0 && g[i-1][j] == '.' && vis.find({i-1, j}) == vis.end()) {
        dfs(g, i-1, j, n, m, k, vis, dep, dept+1);
    }

    if(j-1 >= 0 && g[i][j-1] == '.' && vis.find({i, j-1}) == vis.end()) {
        dfs(g, i, j-1, n, m, k, vis, dep, dept+1);
    }

}

void runTest()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<string> g(n);
    for(ll i=0; i<n; i++) cin >> g[i];

    set<pair<ll,ll>> vis;
    vector<pair<ll, pair<ll,ll>>> dep;

    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(g[i][j] == '.' || vis.find({i, j}) == vis.end())
                dfs(g, i, j, n, m, k, vis, dep, 0);
        }
    }

    sort(dep.begin(), dep.end(), greater<pair<ll, pair<ll,ll>>>());

    for(ll i=0; i<k; i++) {
        auto p = dep[i].second;
        g[p.first][p.second] = 'X';
    }

    for(auto it : g) cout << it << endl;

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