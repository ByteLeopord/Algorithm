/*
多重背包问题限定了一种物品的个数，解决多重背包问题，只需要把它转化为0-1背包问题即可。
比如，有2件价值为5，重量为2的同一物品，我们就可以分为物品a和物品b，a和b的价值都为5，重量都为2，但我们把它们视作不同的物品。
*/
int beibao(vector<int>& value, vector<int>& weight, vector<int>& num, int limit)
{
	int len = value.size();

	vector<vector<int>> dp(len+1, vector<int>(limit+1, 0));
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= limit; j++) {
			for(int k = 0; k <= num[i-1]; k++){
				if (j - k*weight[i-1] >= 0) 
					dp[i][j] = max(dp[i][j], dp[i-1][j - k*weight[i-1]] + k*value[i-1]);
			}
		}
	}

	return dp[len][limit];
}
