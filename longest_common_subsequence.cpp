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

string x{}, y{}, s{};
size_t m{}, n{}, p{};
int t[1000][1000];

void lcs() {
    rep(i, 0, m) {
        rep(j, 0, n) {
            if (i==0||j==0)
                t[i][j] = 0;
            else
                t[i][j] = INT_MIN;
        }
    }
    rep(i, 1, m) {
        rep(j, 1, n) {
            if (x[i-1]==y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    p = t[m][n];
}

void init_lcs_string() {
    size_t i{m}, j{n};
    while (i>0&&j>0) {
        if (x[i-1]==y[j-1]) {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else if (t[i][j-1]>=t[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(s.begin(), s.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    x = "acbcf";
    y = "abcdaf";
    m = x.size();
    n = y.size();
    lcs();
    init_lcs_string();
    cout << p << '|' << s << NL;
    cout << "This is lit!" << NL;
    return 0;
}

