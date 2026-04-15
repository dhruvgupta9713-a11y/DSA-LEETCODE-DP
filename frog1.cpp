// thsi is the top down approach we can also solve with bottom up without using recursion 

#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int>& h, vector<int>& dp) {
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int jump1 = f(i-1, h, dp) + abs(h[i] - h[i-1]);

    int jump2 = INT_MAX;
    if(i > 1) {
        jump2 = f(i-2, h, dp) + abs(h[i] - h[i-2]);
    }

    return dp[i] = min(jump1, jump2);
}

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, -1);

    cout << f(n-1, h, dp);
}
