/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/165/B
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

    ll low = 1, high = n;
    while(low < high) {
        ll v = (low + high)/2;
        ll ktemp = 1;
        ll vsum = 0;
        while(v/ktemp > 0 && vsum < n) {
            vsum += v/ktemp;
            ktemp *= k;
        }

        if(vsum >= n) {
            high = v;
        }else {
            low = v + 1;
        }
    }

    cout << low << endl;
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