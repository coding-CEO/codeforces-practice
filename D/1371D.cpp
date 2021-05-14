/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1371/D
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> ans(n, vector<ll>(n, 0));

    ll i=0, j=0;
    
    while(1) {
        while(i<n && j<n && k > 0) {
            ans[i][j] = 1;
            i++;
            j++;
            k--;
        }
        if(k <= 0) break;
        i = i%n;
        j = j%n;
        if(j == 0) {
            i++;
        }
        if(i >= n) break;
    }

    ll mxr = 0, mnr = INT_MAX;
    ll mxc = 0, mnc = INT_MAX;

    for(ll i=0; i<n; i++) {
        ll cour = 0;
        ll couc = 0;
        for(ll j=0; j<n; j++) {
            if(ans[i][j]) cour++;
            if(ans[j][i]) couc++;
        }
        mxr = max(mxr, cour);
        mnr = min(mnr, cour);
        mxc = max(mxc, couc);
        mnc = min(mnc, couc);
    }

    cout << (mxr - mnr)*(mxr - mnr) + (mxc - mnc)*(mxc - mnc) << endl;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            cout << ans[i][j];
        }
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}