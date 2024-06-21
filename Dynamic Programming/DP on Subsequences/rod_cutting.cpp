// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

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
    int cutRod(int price[], int n) {
        vi f(n+1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++)
                f[j] = max(f[j], f[j-i] + price[i-1]);
        }
        return f[n];
    }
};