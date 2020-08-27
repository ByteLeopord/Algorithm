/*
因为weight和value从0开始计，所有下方第i个物件为i-1
f(i,j) - 在j容量下，有i个物件的最大价值
转换方程：f(i,j) = max{f(i,j), f(i-1, j-k*weight(i-1))+k*value(i-1)}
解释：循环判断是否加入k个i物件，前者f(i,j)为不加，后者为加入k个i物件
*/
int WanQuan(vector<int>& value, vector<int>& weight, int limit)
{
	int len = value.size();
	vector<vector<int>> dp(len + 1, vector<int>(limit + 1, 0));
	for (int i = 1; i <= len; i++){
		for (int j = 0; j <= limit; j++){
			for (int k = 0; k*weight[i-1] <= j; k++){
				dp[i][j] = max(dp[i][j], dp[i-1][j - k*weight[i - 1]] + k*value[i - 1]);	//前：不加k个i物件	后：加k个i物件
			}
		}
	}
	return dp[len][limit];
}
