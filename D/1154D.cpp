/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1154/D
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, a, b;
    cin >> n >> b >> a;

    ll cb = b, ca = a;
    ll ar[n];
    for(ll i=0; i<n; i++) {
        cin >> ar[i];
    }



    for(ll i=0; i<n; i++) {
        if(ar[i]) {
            // sunlight
            if(ca >= a) ca--;
            else if(ca < a && cb > 0) {
                cb--;
                ca++;
            }else if(ca > 0) ca--;
            else {
                cout << i << endl;
                return;
            }
        }else {
            if(ca > 0) ca--;
            else if(cb > 0) cb--;
            else {
                cout << i << endl;
                return;
            }
        }
    }

    cout << n << endl;
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