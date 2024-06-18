// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

/*
MEMOIZATION SOLUTION, passes all the test cases.
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



bool solve(int i, vi& arr, int target, vvi& dp){
    if(target == 0) return true;
    if (i == arr.size()) {
      return false;
    }

    for (; i < arr.size(); i++) {
        if (target - arr[i] < 0)
            continue;
        else if (dp[i + 1][target - arr[i]] == -1) {
            dp[i + 1][target - arr[i]] = solve(i + 1, arr, target - arr[i], dp);
            if(dp[i+1][target - arr[i]] == 1) return true;
        }
        else if (dp[i+1][target-arr[i]] == 1) return true;
    }

    return false;
}


bool subsetSumToK(int n, int k, vi &arr) {
    vvi dp(arr.size()+1, vi (k+1, -1));
    return solve(0, arr, k, dp);
}