// https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m=s2.size();
        vvi f(n+1, vi(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i-1][j], f[i][j-1]); 
            }
        }
        return f[n][m];
    }
};