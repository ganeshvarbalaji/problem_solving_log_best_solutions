// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

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

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vi f(W+1, 0);
        for(int i = 0; i < N; i++){
            for(int j = wt[i]; j <= W; j++)
                f[j] = max(f[j], f[j-wt[i]] + val[i]);
        }
        return f[W];
    }
};