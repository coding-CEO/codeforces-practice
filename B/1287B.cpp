/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1287/B
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

    string a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    if(n <= 2) {
        cout << 0 << endl;
        return;
    }

    map<string,ll> m;
    m[a[0]]++;

    ll ans = 0;
    for(ll i=1; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            string toFind = "";
            for(ll o=0; o<k; o++) {
                ll s = 0, t = 0, e = 0;

                if(a[i][o] == 'S') s++;
                if(a[i][o] == 'T') t++;
                if(a[i][o] == 'E') e++;

                if(a[j][o] == 'S') s++;
                if(a[j][o] == 'T') t++;
                if(a[j][o] == 'E') e++;

                if(s == 2) toFind += 'S';
                else if(t == 2) toFind += 'T';
                else if(e == 2) toFind += 'E';
                else if(s == 1 && t == 1) toFind += 'E';
                else if(s == 1 && e == 1) toFind += 'T';
                else toFind += 'S';
            }
            ans += m[toFind];
        }
        m[a[i]]++;
    }

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