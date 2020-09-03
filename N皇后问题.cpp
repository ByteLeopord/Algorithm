class Solution {
public:
    vector<vector<string>> res;
    bool isOK(int x, int y, int n, vector<string>& used){
        for(int i = 0; i < x; i++){
            if(used[i][y] == 'Q')
                return false;
            if(x-1-i >= 0 && y-1-i >= 0 && used[x-1-i][y-1-i] == 'Q')
                return false;
            if(x-1-i >= 0 && y+1+i < n && used[x-1-i][y+1+i] == 'Q')
                return false;
        }
        return true;
    }

    void solve(int n, vector<string>& used, int index){
        if(index >= n){
            res.push_back(used);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!isOK(index, i, n, used))
                continue;
            used[index][i] = 'Q';
            solve(n, used, index+1);
            used[index][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> used(n, string(n, '.'));
        solve(n, used, 0);
        return res;
    }
};
