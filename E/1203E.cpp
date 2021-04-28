/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1203/E
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

    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    set<ll> se;
    sort(a, a+n);

    for(ll i=0; i<n; i++) {
        if(a[i]-1 > 0 && se.find(a[i]-1) == se.end()) {
            se.insert(a[i]-1);
            continue;
        }
        if(se.find(a[i]) == se.end()) {
            se.insert(a[i]);
            continue;
        }
        if(se.find(a[i]+1) == se.end()) {
            se.insert(a[i]+1);
            continue;
        }
    }

    cout << se.size() << endl;
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