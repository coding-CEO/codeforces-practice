/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/371/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    string s;
    cin >> s;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll rb, rs, rc;
    cin >> rb >> rs >> rc;

    ll r;
    cin >> r;

    //////////

    ll br = 0, sr = 0, cr = 0;
    for(char c : s) {
        if(c == 'B') br++;
        else if(c == 'C') cr++;
        else if(c == 'S') sr++;
    }

    ll low = 0, high = __LONG_LONG_MAX__/10000;
    while(low < high) {
        ll mid = low + (high - low - 1)/2 + 1;

        // cout << low << ' ' << high << endl;

        ll tempr = r;
        ll tb = mid*br - nb;
        tempr -= max(0LL, tb*rb);
        ll ts = mid*sr - ns;
        tempr -= max(0LL, ts*rs);
        ll tc = mid*cr - nc;
        tempr -= max(0LL, tc*rc);

        if(tempr >= 0) {
            low = mid;
        }else {
            high = mid-1;
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