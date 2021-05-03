/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/414/A
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

    if(k < n/2) {
        cout << -1 << endl;
        return;
    }

    if(n == 1) {
        if(k == 0) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }

    ll val = k - (n/2) + 1;

    cout << val << ' ' << 2*val << ' ';
    val = 2*val + 1;
    for(ll i=0; i<n-2; i++) {
        cout << val << ' ';
        val++;
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