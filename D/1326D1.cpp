/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1326/D1
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

bool isPalindrome(string s) {
    ll i = 0, j = s.size() - 1;
    while(i < j && s[i] == s[j]) i++, j--;
    if(i >= j) return true;
    return false;
}

void runTest()
{
    string s;
    cin >> s;
    ll n = (ll)s.size();
    ll i = 0, j = n-1;

    string ans1 = "";

    while(i <= j && s[i] == s[j]){
        ans1 += s[i];
        i++;
        j--;
    }

    if(i > j) {
        cout << s << endl;
        return;
    }

    string t = "";
    string ans = "";
    for(ll ind=i; ind<=j; ind++) {
        t += s[ind];
        if(isPalindrome(t) && t.size() > ans.size()) ans = t;
    }
    t = "";
    for(ll ind=j; ind>=i; ind--) {
        t += s[ind];
        if(isPalindrome(t) && t.size() > ans.size()) ans = t;
    }
    cout << ans1;
    cout << ans;
    reverse(ans1.begin(), ans1.end());
    cout << ans1 << endl;
}

int main()
{

#if !defined(ONLINE_JUDGE)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        runTest();

    return 0;
}