/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1256/D
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
    string s;
    cin >> s;

    ll inv = 0;
    ll oneCou = 0;

    vector<bool> ans(n, false);
    ll cou = 0;

    for(ll i=0; i<n; i++) {
        char c = s[i];
        if(c == '1') {
            oneCou++;
        }else {
            inv = oneCou;
            cou++;
            if(k > inv) {
                k -= inv;
                ans[i-inv] = true;
            }else {
                ans[i-k] = true;
                break;
            }
        }
    }

    vector<char> a(n);
    ll ind = 0;

    for(ll i=0; i<n; i++) {
        char c = s[i];
        if(ans[i]) {
            a[i] = '0';
        }
        if(c == '0' && cou > 0) {
            cou--;
            continue;
        }
        while(ans[ind]) {
            ind++;
        }
        a[ind] = c;
        ind++;
    }

    for(auto i : a) cout << i;
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}