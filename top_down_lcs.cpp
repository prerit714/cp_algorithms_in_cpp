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
int top_down_lcs(string const& x, string const& y, size_t const n, size_t const m) {
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
            if (x[i-1]==y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][m];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x{"abcdgh"};
    string y{"abedfhr"};
    int p{top_down_lcs(x, y, x.size(), y.size())};
    cout << p << NL;
    return 0;
}

