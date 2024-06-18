// https://leetcode.com/problems/partition-equal-subset-sum/description/

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

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vvi grid(n+1, vi (k+1, -1));
        if(arr[n-1] <= k)
        grid[n-1][arr[n-1]] = 1;
        grid[n-1][0] = 1;
        for(int i = n-2; i >= 0; i--){
            grid[i][0] = true;
            if(arr[i] <= k)
                grid[i][arr[i]] = true; 
            for(int j = 0; j < grid[i+1].size(); j++){
                if(grid[i+1][j] == 1){
                    if(arr[i] + j <= k)
                        grid[i][j + arr[i]] = true; 
                    grid[i][j] = true;
                }
            }
        }

        if(grid[0][k] == 1) return true;
        else return false;
    }

    bool canPartition(vi& nums) {
        int sum = 0;
        for(int i : nums) sum +=  i;
        if(sum%2 == 1) return false;
        if(subsetSumToK(nums.size(), sum/2, nums)) return true;
    }
};