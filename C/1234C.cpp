/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1234/C
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

    vector<string> a(2);
    cin >> a[0];
    cin >> a[1];

    ll i=0, j=0, dir = 0; // 0 = horizontal, 1 = vertical
    while(i < 2 && j < n) {
        if(a[i][j] >= '1' && a[i][j] <= '2') {
            // I shape
            if(dir == 0) {
                j++;
            }else {
                cout << "NO" << endl;
                return;
            }
        } else {
            // L shape
            if(dir == 0) {
                i = (i+1)%2;
                dir = 1;
            }else {
                dir = 0;
                j++;
            }
        }
    }

    if(i == 1 && j == n) cout << "YES" << endl;
    else cout << "NO" << endl;

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