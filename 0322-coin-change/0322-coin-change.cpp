class Solution {
public:
    // int minAns=INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        // Method 1 Executor
        // vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, -1));
        // int ans = helper(coins, amount, 0, dp);
        // if(ans==INT_MAX-1) return -1;
        // return ans;
        
// //         Method 2
//         vector<int> dp(amount+1,-1);
//         int ans = helper(coins, amount, dp);
        
//         if(ans==INT_MAX) return -1;
//         return ans;
      // method 3
         int ans = helper(coins, amount);
        if(ans==INT_MAX) return -1;
        return ans;
        
    }       
        
    
    
    // Method 1
//     int helper(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
        
        
//         if(amount==0){
//             return 0;
//         }
//         if(amount<0 || i>=coins.size()) return INT_MAX-1;
        
//         if(dp[i][amount] != -1) return dp[i][amount];
        
//         int op1 = 1 + helper(coins, amount-coins[i], i, dp);
//         int op2 = helper(coins, amount, i+1, dp);
//         dp[i][amount] = min(op1,op2);
//         return dp[i][amount];
//         // return min(op1,op2);
//     }
    
    
// //     Method 2
    
//         int helper(vector<int> &coins, int amount, vector<int> &dp){
//             if(amount==0) return 0;
//             if(amount<0) return INT_MAX;
            
//             if(dp[amount]!=-1) return dp[amount];
            
//             int minAns=INT_MAX;
//             for(int i=0;i<coins.size();i++){
//                 int ans = helper(coins, amount-coins[i], dp);
//                 if(ans!=INT_MAX) minAns = min(1+ans, minAns);
//             }
//             dp[amount] = minAns;
            
//             return dp[amount];
            
//         }
    
//     Method 3 (Tabulation Bottom Up DP)
    
    int helper(vector<int> &coins, int amount){
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount];
    }
    
};