/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1313/C1
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

    ll ans = -1;
    ll ind = -1;
    for(ll i=0; i<n; i++) {
        ll sum = a[i];
        ll j = i-1;
        ll maxi = a[i];
        while(j >= 0) {
            maxi = min(maxi, a[j]);
            sum += maxi;
            j--;
        }
        j = i+1;
        maxi = a[i];
        while(j < n) {
            maxi = min(maxi, a[j]);
            sum += maxi;
            j++;
        }

        if(sum > ans) {
            ans = sum;
            ind = i;
        }
    }

    vector<ll> ansv(n);
    ansv[ind] = a[ind];
    ll j = ind-1;
    ll maxi = a[ind];
    while(j >= 0) {
        maxi = min(maxi, a[j]);
        ansv[j] = maxi;
        j--;
    }
    j = ind+1;
    maxi = a[ind];
    while(j < n) {
        maxi = min(maxi, a[j]);
        ansv[j] = maxi;
        j++;
    }

    for(ll i=0; i<n; i++) cout << ansv[i] << ' ';
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