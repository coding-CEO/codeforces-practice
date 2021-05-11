/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1348/C
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

    sort(s.begin(), s.end());

    if(k == 1) {
        cout << s << endl;
        return;
    }

    ll mini = 0;
    set<char> se;
    for(char c : s) {
        if(c == s[0]) mini++;
        se.insert(c);
    }

    if(mini >= k) {
        if(se.size() > 2 || (mini > k && se.size() > 1)) {
            for(ll i=k-1; i<n; i++) cout << s[i];
            cout << endl;
        }else {
            for(ll i=0; i<n; i+=k) cout << s[i];
            cout << endl;
        }
    }else {
        cout << s[k-1] << endl;
    }

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