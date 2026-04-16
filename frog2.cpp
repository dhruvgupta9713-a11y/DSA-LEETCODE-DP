#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int f(int i, vector<int>& h, vector<int>& dp,int k) {
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];
     int jump=INT_MAX;
    for(int j=1;j<=k;j++){
      if(i-j >=0){
        jump= min (jump,f(i-j, h, dp,k) + abs(h[i] - h[i-j]));
      }
    }

    return dp[i] =jump;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin>>k;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, -1);

    cout << f(n-1, h, dp,k);
}