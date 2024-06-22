// https://leetcode.com/problems/shortest-common-supersequence/description/

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
    string longest_common_supersequence(string s, string t, int n, int m){
        vvi f(n+1, vi(m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else{
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }

        string LCS = "";
        while(n != 0 and m != 0){
            if(s[n-1] == t[m-1]){
                LCS += s[n-1];
                n--;
                m--;
            }
            else {
                if(f[n-1][m] > f[n][m-1]){
                    LCS += s[n-1];
                    n--;
                }
                else{
                    LCS += t[m-1];
                    m--;
                }
            }
        }
        while(n > 0) {LCS += s[n-1]; n--;}
        while(m > 0) {LCS += t[m-1]; m--;}
        reverse(LCS.begin(), LCS.end());
        return LCS;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return longest_common_supersequence(str1, str2, str1.size(), str2.size());
    }
};