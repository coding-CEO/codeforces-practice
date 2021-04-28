/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1283/C
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

    ll a[n+1];
    for(ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> ans(n+1, -1);
    vector<ll> out(n+1, 0), in(n+1, 0);

    for(ll i=1; i<=n; i++) {
        if(a[i] > 0) {
            ans[i] = a[i];
            out[i]++;
            in[a[i]]++;
        }
    }

    vector<ll> outL;
    deque<ll> inL;
    for(ll i=1; i<=n; i++) if(out[i] == 0) outL.push_back(i);
    for(ll i=1; i<=n; i++) if(in[i] == 0) inL.push_back(i);

    if(outL.size() > 0 && outL[outL.size()-1] == inL.back()) {
        ll val = inL.back();
        inL.pop_back();
        inL.push_front(val);
    }

    for(ll i=0; i<outL.size(); i++) {
        if(outL[i] != inL.front()) {
            ans[outL[i]] = inL.front();
            inL.pop_front();
        } else {
            ll val = inL.front();
            inL.pop_front();
            ans[outL[i]] = inL.front();
            inL.pop_front();
            inL.push_front(val);
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