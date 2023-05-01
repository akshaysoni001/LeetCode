class Solution {
public:
    int result=0;
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int> (matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                if(matrix[i][j]==1){
                 int ans = helper(matrix, i, j, dp);
                 result+=ans;
                }
            }
        }
        
        return result;
    }
    
    int helper(vector<vector<int>> &m, int i, int j, vector<vector<int>> &dp){
        
        if(i>=m.size() || j>=m[0].size() || m[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        int right = helper(m, i, j+1, dp);
        int down  = helper(m, i+1, j, dp);
        int rightDig = helper(m, i+1, j+1, dp);
        
            // cout<<right<<"-"<<down<<"-"<<rightDig<<endl;
            count += 1 + min(right, min(down, rightDig));
        return dp[i][j]=count;
    }
};