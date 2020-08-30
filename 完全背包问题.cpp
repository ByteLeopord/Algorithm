/*
完全背包问题
因为weight和value从0开始计，所有下方第i个物件为i-1
f(i,j) - 在j容量下，有i个物件的最大价值
转换方程：f(i,j) = max{f(i,j), f(i-1, j-k*weight(i-1))+k*value(i-1)}
解释：循环判断是否加入k个i物件，前者f(i,j)为不加，后者为加入k个i物件
*/
/*
	常规解法
    输入物品重量weight 和 价值value，以及背包容量limit
    输出背包可容纳最大价值
    每个物品可选无数次
*/
int beibaoinf(vector<int>& weight, vector<int>& value, int limit)
{
	int len = weight.size();
	vector<vector<int>> dp(len+1, vector<int>(limit+1, 0));
	for(int i = 1; i <= len; i++){
		for(int j = limit; j >= 0; j--){
			for(int k = 0; k <= j/weight[i-1]; k++){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*weight[i-1]]+k*value[i-1]);
			}
		}
	}
	return dp[len][limit];
}
//一维空间优化
int beibaoinf(vector<int>& weight, vector<int>& value, int limit)
{
	int len = weight.size();
	vector<int> dp(limit+1, 0);
	for(int i = 1; i <= len; i++){
		for(int j = limit; j >= 0; j--){
			for(int k = 0; k <= j/weight[i-1]; k++){
				dp[j] = max(dp[j], dp[j-k*weight[i-1]]+k*value[i-1]);
			}
		}
	}
	return dp[len][limit];
}
//逻辑优化
//顺向遍历
int beibaoinf(vector<int>& weight, vector<int>& value, int limit)
{
	int len = weight.size();
	vector<int> dp(limit+1, 0);
	for(int i = 1; i <= len; i++){
		for(int j = weight[i-1]; j <= limit; j++){
			dp[j] = max(dp[j], dp[j-weight[i-1]]+value[i-1]);
		}
	}
	return dp[limit];
}
