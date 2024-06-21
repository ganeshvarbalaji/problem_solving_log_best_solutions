// https://leetcode.com/problems/coin-change/description/


/*
Complete Knapsack problem:
https://cp-algorithms.com/dynamic_programming/knapsack.html#complete-knapsack
 */
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution {
public:

    /* OLD CODE */
    // int coinChange(vi& coins, int amount) {
    //     if(amount == 0) return 0;
    //     int n = coins.size();
    //     vi prev(amount+1, INT_MAX);
    //     for(int j = 1; j * coins[n-1] <= amount; j++){
    //         prev[j*coins[n-1]] = j;
    //     }

    //     for(int i = n-2; i >= 0; i--){
    //         int coin = coins[i];
    //         for(int j = 1; j*coin <= amount; j++){
    //             prev[j*coin] = min(j, prev[j*coin]);

    //             for(int k = 1; k + j*coin <= amount; k++){
    //                 if(prev[k] != INT_MAX)
    //                 prev[j*coin + k] = min(prev[k] + j, prev[j*coin + k]);
    //             }
    //         }
    //     }

    //     if(prev[amount] == INT_MAX){
    //         return -1;
    //     }
    //     else return prev[amount];
    // }

    int coinChange(vi& coins, int amount) {
        int n = coins.size();
        vi f(amount+1, amount+1);
        f[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        if(f[amount] == amount+1) return -1;
        return f[amount];
    }
};
