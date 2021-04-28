/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1106/D
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
    
    vector<vector<ll>> g(n+1);
    for(ll i=0; i<m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> isTaken(n+1, false);
    isTaken[1] = true;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(1);

    while(!q.empty()) {
        ll v = q.top();
        q.pop();
        cout << v << ' ';

        for(ll adj : g[v]) {
            if(!isTaken[adj]) {
                isTaken[adj] = true;
                q.push(adj);
            }
        }
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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}