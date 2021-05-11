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
int lcs(const string& x, const string& y, size_t n, size_t m) {
    if (n==0||m==0)
        return 0;
    if (x[n-1]==y[m-1])
        return 1+lcs(x, y, n-1, m-1);
    return max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x{"abcdgh"};
    string y{"abcdfhr"};
    size_t n{x.size()};
    size_t m{y.size()};
    int p{lcs(x, y, n, m)};
    cout << p << endl;
    return 0;
}
