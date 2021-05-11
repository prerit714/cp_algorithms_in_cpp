#include <bits/stdc++.h>
using namespace std;

string x{}, y{}, s{};
size_t m{0}, n{0}, p{0};
int t[1000][1000];

void lcp() {
    for (int i{0}; i<=m; ++i) {
        for (int j{0}; j<=n; ++j) {
            if (i==0||j==0)
                t[i][j] = 0;
            else
                t[i][j] = INT_MIN;
        }
    }
    for (int i{1}; i<=m; ++i) {
        for (int j{1}; j<=n; ++j) {
            if (x[i-1]==y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            /*
                In here if you wish to find the longest common
                palindromic substring, just use the code below
                else
                    t[i][j] = 0;
                this will work in all cases where you need a
                substring instead of subsequence!
                Also make sure that you are using right value
                of m and n (which is the max value's i, j)
                in case you wish to print the sequence
            */
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    p = t[m][n];
}

void init_string() {
    size_t i{m}, j{n};
    while (i>0&&j>0) {
        if (x[i-1]==y[j-1]) {
            s.push_back(x[i-1]);
            i--;
            j--;
        } else if (t[i][j-1]>=t[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(s.begin(), s.end());
}

int main() {
    x = "agbcba";
    y = x;
    reverse(y.begin(), y.end());
    m = x.size();
    n = y.size();
    lcp();
    init_string();
    cout << p << endl;
    cout << s << endl;
    return 0;
}