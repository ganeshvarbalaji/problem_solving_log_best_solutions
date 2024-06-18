// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

vvi grid;

bool subsetSumToK(int n, int k, vector<int> &arr) {
	grid = vvi (n+1, vi (k+1, -1));
	if(arr[n-1] <= k)
	grid[n-1][arr[n-1]] = 1;
	grid[n-1][0] = 1;
	for(int i = n-2; i >= 0; i--){
		grid[i][0] = true;
		if(arr[i] <= k)
			grid[i][arr[i]] = true; 
		for(int j = 0; j < grid[i+1].size(); j++){
			if(grid[i+1][j] == 1){
				if(arr[i] + j <= k)
					grid[i][j + arr[i]] = true; 
				grid[i][j] = true;
			}
		}
	}
}

int minSubsetSumDifference(vector<int>& nums, int n) {
	int sum = 0;
	for(int i : nums)
		sum += i;

	int k = sum/2;
	grid = vvi (n+1, vi (k+1, -1));
	subsetSumToK(n, k, nums);

	if(grid[0][k] == 1){
		return abs((sum - k) - k);
	}
	else{
		for(int i = k; i >= 0; i--){
			if(grid[0][i] == 1){
				return abs((sum - i) - i);
			}
		}
	}
	return -1;
}