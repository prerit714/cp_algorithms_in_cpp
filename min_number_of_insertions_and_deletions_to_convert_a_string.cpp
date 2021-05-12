#include <bits/stdc++.h>
using namespace std;

int lcs(const string& x, const string& y, size_t m, size_t n) {
    int t[m+1][n+1];
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
            if (x[i-1]==y[j-1]) {
                t[i][j] = 1+t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

pair<int, int> min_insertions_and_deletions(const string& x, const string& y) {
    size_t m{x.size()};
    size_t n{y.size()};
    int lcs_xy{lcs(x, y, m, n)};
    pair<int, int> q{0, 0};
    // if (m>n) {
    //     q.first = m-lcs_xy; // deletions
    //     q.second = n-lcs_xy; // insertions
    // }
    q.first = ((m>n) ? m-lcs_xy: n-lcs_xy);
    q.second = ((m>n) ? n-lcs_xy: m-lcs_xy);
    return q;
}

int main() {
    string heap{"heap"};
    string pea{"pea"};
    pair<int, int> q{min_insertions_and_deletions(pea, heap)};
    cout << q.first << " insertions" << ' ' << q.second << " deletions" << endl;
    return 0;
}