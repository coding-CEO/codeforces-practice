/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1466/D
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

    pair<ll,ll> w[n];
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        cin >> w[i].first;
        sum += w[i].first;
        w[i].second = 0;
    }
    for(ll i=0; i<n-1; i++) {
        ll u, v;
        cin >> u >> v;
        w[u-1].second++;
        w[v-1].second++;
    }

    sort(w, w+n, greater<pair<ll,ll>>());

    cout << sum << ' ';
    ll ind = 0;
    for(ll k=0; k<n-2; k++) {
        while(ind<n && w[ind].second <= 1) {
            ind++;
        }
        if(ind >= n) {
            cout << sum << ' ';
        }else {
            sum += w[ind].first;
            w[ind].second--;
            cout << sum << ' ';
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}