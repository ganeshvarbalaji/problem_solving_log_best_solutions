// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

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
    int longestCommonSubstr(string s, string t, int n, int m) {
        vvi f(n+1, vi(m+1, 0));
        int max_len = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    f[i][j] = f[i-1][j-1] + 1;
                    max_len = max(max_len, f[i][j]);
                }
            }
        }
        return max_len;
    }
};