/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1327/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i=0; i<k; i++) {
        ll x, y;
        cin >> x >> y;
    }
    for(ll i=0; i<k; i++) {
        ll x, y;
        cin >> x >> y;
    }

    /////////////
    string ans = "";

    for(ll i=0; i<n-1; i++) ans += 'U';
    for(ll i=0; i<m-1; i++) ans += 'L';

    ll dir = 1;
    ll j = 0;
    ll row = 0;
    while(1) {
        if(dir) {
            // right
            if(j+1 < m) {
                ans += 'R';
                j++;
            }else if(row+1 < n){
                ans += 'D';
                row++;
                dir = 0;
            }else break;
        }else {
            // left
            if(j-1 >= 0) {
                ans += 'L';
                j--;
            }else if(row+1 < n){
                ans += 'D';
                row++;
                dir = 1;
            }else break;
        }
    }

    cout << ans.size() << endl;
    cout << ans << endl;
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