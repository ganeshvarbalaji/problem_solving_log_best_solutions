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
