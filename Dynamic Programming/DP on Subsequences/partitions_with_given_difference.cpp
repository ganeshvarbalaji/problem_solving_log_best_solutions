// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

/*
sum - s2 - s2 = d
s2 = (sum-d)/2
 */

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define vvii vector<vector<pair<int,int>>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
#define ll long long
#define vll vector<long long>
#define mod 1000000007

int findWays(vi& arr, int k){
    int n = arr.size();
    vvi dp(n, vi (k+1, 0));
    dp[n-1][0]++;
    if(arr[n-1] <= k)  
    dp[n-1][arr[n-1]]++;

    for(int i = n-2; i >= 0; i--){
        dp[i] = dp[i+1];
        for(int j = 0; j <= k; j++){
          if (arr[i] + j <= k) {
            dp[i][arr[i] + j] += dp[i + 1][j];
            dp[i][arr[i] + j] %= mod;
          }
        }
    }

    return dp[0][k]%mod;
}


int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i : arr) sum += i;
    if(sum-d < 0) return 0;
    if((sum-d)%2 == 1) return 0;
    return findWays(arr, (sum-d)/2);
}
