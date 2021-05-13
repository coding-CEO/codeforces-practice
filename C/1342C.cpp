/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1342/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll ans(ll r, ll len, ll pre[]) {
    ll blocks = r/len;
    ll rem = r%len;

    return pre[len]*blocks + pre[rem];
}

ll ans(ll l, ll r, ll len, ll pre[]) {
    return ans(r, len, pre) - ans(l-1, len, pre);
}

void runTest()
{
    ll a, b, q;
    cin >> a >> b >> q;

    ll len = a*b;
    ll pre[len+1];
    pre[0] = 0;
    for(ll i=1; i<=len; i++) {
        pre[i] = pre[i-1];
        if(((i%b)%a) != ((i%a)%b))
            pre[i]++;
    }

    while(q--) {
        ll l, r;
        cin >> l >> r;

        cout << ans(l, r, len, pre) << ' ';
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