#include <bits/stdc++.h>
using namespace std;
typedef	vector<int>         vi;
typedef	vector<string>      vs;
typedef vector<char>        vc;
typedef	pair<int, int>      pii;
typedef	vector<pii>         vpii;
typedef	vector<vi>          vvi;
typedef long long           ll;
#define	rep(i, a, b)        for(auto i{a}; i<=(b); ++i)
#define	repx(i, a, b, x)    for(auto i{a}; i<=(b); i+=(x))
#define	itr(i, v)           for(auto i{v.begin()}; i!=v.end(); ++i)
#define	ritr(i, v)          for(auto i{v.rbegin()}; i!=v.rend(); ++i)
#define MP                  make_pair
#define	PB                  push_back
#define	F                   first
#define	S                   second
#define NL                  '\n'
#define SQ(a)               (a)*(a)
#define CB(a)               (a)*(a)*(a)
#define Log(x)              cout << x << endl
#define Err(x)              cout << x << endl
#define SIZE(v)             (sizeof(v)/sizeof(v[0]))
int longest_common_substring(const string& a, const string& b, size_t n, size_t m) {
    int t[n+1][m+1];
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (i==0||j==0)
                t[i][j] = 0;
            else
                t[i][j] = INT_MIN;
        }
    }
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (a[i-1]==b[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = 0;
        }
    }
    int mx{INT_MIN}; // to store the max length
    rep(i, 0, n) {
        rep(j, 0, m) {
            mx = max(mx, t[i][j]);
        }
    }
    return mx;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x{"abcde"};
    string y{"abfce"};
    int p{longest_common_substring(x, y, x.size(), y.size())};
    Log(p);
    return 0;
}

