// https://leetcode.com/problems/coin-change-ii/

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
    int change(int amount, vi& coins) {
        int n = coins.size();
        vi f(amount+1, 0);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            int c = coins[i];
            for(int j = c; j <= amount; j++){
                f[j] += f[j - c];
            }
        }
        return f[amount];
    }
};