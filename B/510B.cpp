/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/510/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

bool dfs(auto &g, ll i, ll j, ll pari, ll parj, auto &vis, auto &ongoing) {
    vis[i][j] = true;
    ongoing[i][j] = true;

    // cout << i << ' ' << j << endl;

    if(j+1 < g[i].size() && g[i][j+1] == g[i][j]) {
        if(j+1 != parj) {
            if(ongoing[i][j+1]) return true;
            if(!vis[i][j+1] && dfs(g, i, j+1, i, j, vis, ongoing)) return true;
        }
    }
    if(j-1 >= 0  && g[i][j-1] == g[i][j]) {
        if(j-1 != parj) {
            if(ongoing[i][j-1]) return true;
            if(!vis[i][j-1] && dfs(g, i, j-1, i, j, vis, ongoing)) return true;
        }
    }
    if(i+1 < g.size() && g[i+1][j] == g[i][j]) {
        if(i+1 != pari) {
            if(ongoing[i+1][j]) return true;
            if(!vis[i+1][j] && dfs(g, i+1, j, i, j, vis, ongoing)) return true;
        }
    }
    if(i-1 >= 0 && g[i-1][j] == g[i][j]) {
        if(i-1 != pari) {
            if(ongoing[i-1][j]) return true;
            if(!vis[i-1][j] && dfs(g, i-1, j, i, j, vis, ongoing)) return true;
        }
    }

    ongoing[i][j] = false;

    return false;
}

void runTest()
{
    ll n, m;
    cin >> n >> m;

    vector<string> g(n);
    for(ll i=0; i<n; i++) cin >> g[i];

    vector<vector<bool>> vis(n, vector<bool>(m, false)), 
    ongoing(n, vector<bool>(m, false));

    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            // cout << "here";
            if(!vis[i][j]) {
                if(dfs(g, i, j, i, j, vis, ongoing)) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "No" << endl;
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