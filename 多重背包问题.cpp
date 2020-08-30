/*
多重背包问题限定了一种物品的个数，解决多重背包问题，只需要把它转化为0-1背包问题即可。
比如，有2件价值为5，重量为2的同一物品，我们就可以分为物品a和物品b，a和b的价值都为5，重量都为2，但我们把它们视作不同的物品。
*/
int beibao(vector<int>& value, vector<int>& weight, int limit)
{
	int len = value.size();
	
	vector<int> dp(limit+1, 0);
	for (int i = 1; i <= len; i++) {
        for (int j = limit; j >= 0; j--) {
            if (weight[i] <= j) 
				dp[j] = max(dp[j], dp[j - weight[i-1]] + value[i-1]);
        }
    }
	
	return dp[limit];
}
