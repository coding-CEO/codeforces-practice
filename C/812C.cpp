/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/812/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, s;
    cin >> n >> s;

    ll a[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    // sort(a, a+n);

    ll low = 0, high = n;
    ll su = 0;
    while(low < high){
        ll mid = ((low + high - 1) / 2)+1;
        ll b[n];
        for(ll i=0; i<n; i++) {
            b[i] = a[i] + (i+1)*mid;
        }
        sort(b, b+n);
        ll sum = 0;
        for(ll i=0; i<mid; i++) {
            sum += b[i];
        }

        if(sum <= s) {
            low = mid;
            su = sum;
        } else {
            high = mid-1;
        }
    }

    cout << low << ' ' << su << endl;
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