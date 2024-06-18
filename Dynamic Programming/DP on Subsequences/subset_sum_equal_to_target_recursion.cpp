// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

/*
This code gives a TLE. This is the recursion solution.
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




bool solve(int i, vi& arr, int target){
    if(target == 0) return true;
    if(target < 0) return false;
    if(i == arr.size()) return false;

    for(int i = 0; i < arr.size(); i++){
        bool a = solve(i+1, arr, target-arr[i]);
        if(a) return true;
    }

    return false;
}


bool subsetSumToK(int n, int k, vi &arr) {

    return solve(0, arr, k);

}