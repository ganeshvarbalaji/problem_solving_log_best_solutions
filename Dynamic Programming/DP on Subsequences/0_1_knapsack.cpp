// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

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
    /* OLD CODE */
    // int knapSack(int W, int wt[], int val[], int n) { 
    //     vvi grid(n, vi (W+1, 0));
    //     if(wt[n-1] <= W) grid[n-1][wt[n-1]] = val[n-1];

    //     for(int i = n-2; i >= 0; i--){
    //         grid[i] = grid[i+1];
    //         if(wt[i] <= W){
    //             if(grid[i][wt[i]] < val[i])
    //                 grid[i][wt[i]] = val[i];
    //         }
    //         else continue;

    //         for(int j = 0; wt[i] + j <= W; j++){
    //             if(grid[i+1][j] > 0)
    //                 grid[i][wt[i] + j] = max(val[i] + grid[i+1][j], grid[i][wt[i] + j]);
    //         }
    //     }

    //     return *max_element(grid[0].begin(), grid[0].end());
    // }


    /* NEW CODE - WORLD STANDARD*/
    int knapSack(int W, int wt[], int val[], int n) { 
        vi f(W+1, 0) ;
        for(int i = 0; i < n; i++){
            for(int j = W; j >= wt[i]; j--)
                f[j] = max(f[j], val[i] + f[j - wt[i]]);
        }
        return *max_element(f.begin(), f.end());
    }
    
};
