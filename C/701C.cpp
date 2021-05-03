/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/701/C
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

    string s;
    cin >> s;

    set<char> se;
    for(char c : s) se.insert(c);

    ll uni = se.size();

    unordered_map<char, ll> fre;
    ll i=0, j=0;
    ll ans = n;

    while(i < n && j < n) {
        fre[s[j]]++;
        while(fre[s[i]] > 1) {
            fre[s[i]]--;
            i++;
        }
        if(fre.size() >= uni) {
            ans = min(ans, j-i+1);
        }
        j++;
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