/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/441/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> ans(k);
    ll limit = m;
    ll cou = 0;
    ll i = 0;
    ll j = 0;

    ///////////////////////
    
    ll dir = 1;
    for(i=0; i<n; i++) {
        while(j>=0 && j<m && cou < k) {
            ans[cou].push_back({i+1, j+1});
            if(j+dir >= 0 && j+dir < m) {
                ans[cou].push_back({i+1, j+1+dir});
                cou++;
                j += 2*dir;
            }else {
                dir *= -1;
                ans[cou].push_back({i+2, j+1});
                cou++;
                j += dir;
                if(cou >= k) i++;
                break;
            }
        }
        if(cou >= k) break;
        if(j < 0) j = 0, dir *= -1;
        if(j >= m) j = m-1, dir *= -1;
    }

    ////////////////////////
    if(j < 0 || j >= m) {
        i++;
        dir *= -1;
        if(j < 0) j = 0;
        if(j >= m) j = m-1;
    }

    for(; i<n; i++) {
        while(j>=0 && j<m) {
            ans[k-1].push_back({i+1, j+1});
            j += dir;
        }
        if(j < 0) {
            j = 0;
            dir *= -1;
        }
        if(j >= m) {
            j = m-1;
            dir *= -1;
        }
    }

    // cout << i << ' ' << j << endl;

    for(auto it : ans) {
        cout << it.size() << ' ';
        for(auto i : it) cout << i.first << ' ' << i.second << ' ';
        cout << endl;
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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}