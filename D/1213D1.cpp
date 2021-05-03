/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1213/D1
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

    ll limit = 200001;

    vector<vector<ll>> ans(limit);
    for(ll i=0; i<n; i++) {
        ll val;
        cin >> val;
        ll cou = 0;
        while(val >= 0) {
            ans[val].push_back(cou);
            if(val <= 0) break;
            val /= 2;
            cou++;
        }
    }

    ll finalAns = INT_MAX;
    for(ll i=0; i<limit; i++) {
        auto it = ans[i];
        if(it.size() < k) continue;

        sort(it.begin(), it.end());
        finalAns = min(finalAns, (ll)accumulate(it.begin(), it.begin()+k, 0));
    }
    cout << finalAns << endl;
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