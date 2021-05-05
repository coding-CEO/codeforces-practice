/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1196/C
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
    priority_queue<pair<ll, bool>> qx, qy;

    ll limit = 100000;
    
    for(ll i=0; i<n; i++) {
        ll xc, yc, l, u, r, d;
        cin >> xc >> yc >> l >> u >> r >> d;

        if(l && r) {
            qx.push({limit, true});
            qx.push({-limit, false});
            // x[0]++;
            // x[limit-1]--;
        }else if(l) {
            qx.push({limit, true});
            qx.push({-xc, false});
            // x[0]++;
            // x[xc+hlimit+1]--;
        }
        else if(r) {
            qx.push({-xc, true});
            qx.push({-limit, false});
            // x[xc+hlimit]++;
            // x[limit-1]--;
        }else {
            qx.push({-xc, true});
            qx.push({-xc, false});
            // x[xc+hlimit]++;
            // x[xc+hlimit+1]--;
        }

        /////

        if(u && d) {
            qy.push({limit, true});
            qy.push({-limit, false});
        }else if(d) {
            qy.push({limit, true});
            qy.push({-yc, false});
        }
        else if(u) {
            qy.push({-yc, true});
            qy.push({-limit, false});
        }else {
            qy.push({-yc, true});
            qy.push({-yc, false});
        }
    }

    ll xc = limit, yc = limit;
    ll res = 0;
    while(!qx.empty()) {
        auto it = qx.top();
        qx.pop();
        if(it.second) {
            res++;
        }else {
            res--;
        }
        if(res == n) xc = -it.first;
    }
    res = 0;
    while(!qy.empty()) {
        auto it = qy.top();
        qy.pop();
        if(it.second) {
            res++;
        }else {
            res--;
        }
        if(res == n) yc = -it.first;
    }

    if(xc == limit || yc == limit) {
        cout << 0 << endl;
    }else {
        cout << 1 << ' ' << xc << ' ' << yc << endl;
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