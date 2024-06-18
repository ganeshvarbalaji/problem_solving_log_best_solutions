// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

/*

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