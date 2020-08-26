/*
game_0记录物品的价值、game_1记录物品的重量、x记录背包容量
dp[len+1][x+1]记录len种物品时、背包装入x重量时 最大价值
dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]])
解释：不放第i件物品 和 放第i件物品 取较大值
*/
int dfs(vector<vector<int>>& game, int x){
    int len = game.size();
    vector<vector<int>> dp(len+1, vector<int>(x+1, 0));
    for(int i = 1; i <= len; i++){
        int w = game[i-1][1];
        int v = game[i-1][0];
        for(int j = 1; j <= x; j++){
            //判断是否放得下,放得下则比较 放与不放 
			if(j >= w)
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[len][x];
    //节约空间 一维数组做法
    //for(int i = 0; i < len; i++){
    //    int w = game[i][1];
    //    int v = game[i][0];
    //    for(int j = x; j >= w; j--)
    //        dp[j] = max(dp[j], dp[j-w]+v);
    //}
    //return dp[x];
}
