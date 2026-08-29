class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int t = 0, b = n - 1;
        int l = 0, r = n - 1;
        int v = 1;
        
        while (v <= n * n) {
            for (int j = l; j <= r; j++) {
                ans[t][j] = v++;
            }
            t++;
            
            for (int i = t; i <= b; i++) {
                ans[i][r] = v++;
            }
            r--;
            
            for (int j = r; j >= l; j--) {
                ans[b][j] = v++;
            }
            b--;
            
            for (int i = b; i >= t; i--) {
                ans[i][l] = v++;
            }
            l++;
        }
        
        return ans;
    }
};