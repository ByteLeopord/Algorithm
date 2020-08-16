#include <iostream>
#include <vector>
#include <algorithm>
/*
T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
对于在第i天结束的时候手里没有股票的情况下，在这一天所能采取的操作有两种
1.不进行交易，即最大收益为T[i-1][k][0]
2.进行卖出，即第i天的最大收益为上一天有股票时的最大收益加上当天的卖价为T[i-1][k][1] + prices[i]

T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])
在第i天结束手里有股票时，同样有两种操作：
1.不进行交易，即为T[i-1][k][0]
2.进行买入，这时的买入增加了一次交易次数，那么i-1天结束的最大交易次数为k-1，即当天结束的最大收益为T[i-1][k-1][0] - prices[i]
*/
//只能买入卖出1次
int onlyone(vector<int>& a){
    int len = a.size();
    if(len <= 1) return 0;
    int dik_0 = 0, dik_1 = -a[0];
    for(int i = 1; i < len; i++){
        dik_1 = max(-a[i], dik_1);        //最便宜的买入时机
        dik_0 = max(dik_1+a[i], dik_0);     //卖出，不卖：最大利润
    }
    return dik_0;
}

//可以买入卖出无数次
int anytimes(vector<int>& a){
    int len = a.size();
    if(len <= 1) return 0;
    int dik_0 = 0, dik_1 = -a[0];
    for(int i = 1; i < len; i++){
        dik_1 = max(dik_0-a[i], dik_1);      //持有股票
        dik_0 = max(dik_1+a[i], dik_0);      //卖出，不卖：最大利润
    }
    return dik_0;
}

//可以买入卖出k次
int ktimes(vector<int>& a, int k){
    int len = a.size();        
    if(len <= 1) return 0;
    if(k > len/2) return anytimes(a);
    vector<vector<vector<int>>> dp(len, vector<vector<int>>(k+1, vector<int>(2, 0)));
    for(int i = 1; i <= k; i++){
        dp[0][i][0] = 0;
        dp[0][i][1] = -a[0];
    }

    for(int i = 1; i < len; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+a[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-a[i]);
        }
    }
    
    return dp[len-1][k][0];
}

//可以买入卖出无数次 但只能隔天买入
int anytimescooldown(vector<int>& a){
    int len = a.size();
    if(len <= 1) return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -a[0];
    dp[1][0] = max(dp[0][0], dp[0][1]+a[1]);
    dp[1][1] = max(dp[0][1], dp[0][0]-a[1]);
    for(int i = 2; i < len; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][0]-a[i]);
    }
    return dp[len-1][0];
}

//可以买入卖出无数次，每次需要交手续费
int anytimesfee(vector<int>& a, int fee){
    int len = a.size();
    if(len <= 1) return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -a[0];
    for(int i = 1; i < len; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i]-fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-a[i]);
    }
    
    return dp[len-1][0];
}

int main() {
    vector<int> input;
    int num;
    while(cin >> num){
        input.push_back(num);
    }
    
    cout << onlyone(input) << endl;
    cout << anytimes(input) << endl;
    cout << ktimes(input, 1) << endl;
    cout << anytimescooldown(input) << endl;
    cout << anytimesfee(input, 2) << endl;
}
