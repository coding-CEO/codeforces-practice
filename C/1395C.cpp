/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1395/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m;
    cin >> n >> m;

    ll a[n], b[m];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    for(ll i=0; i<m; i++) {
        cin >> b[i];
    }

    for(ll val = 0; val < (1 << 9); val++) {
        bool flag2 = true;
        for(auto it : a) {
            bool flag = false;
            for(auto it2 : b) {
                ll temp = (it&it2)|val;
                if(temp == val) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                flag2 = false;
                break;
            }
        }
        if(flag2) {
            cout << val << endl;
            return;
        }
    }

    assert(false);
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