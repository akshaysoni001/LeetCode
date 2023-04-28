class Solution {
public:
    int countSubstrings(string s) {
        
        vector<vector<int>> tab(s.size(), vector<int>(s.size()));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if (i == j) {
                    tab[i][j] = 1;
                } else if (i + 1 == j) {
                    tab[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    tab[i][j] = s[i] == s[j] ? tab[i+1][j-1] : 0;
                }
                count += tab[i][j];
            }
        }
        return count;
    }
//         vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
//         int count=0;
//         for(int i=0;i<s.size();i++){
//        
        // for(int j=i;j<s.size();j++){
//                 if(dp[i][j]!=-1) {
//                     count += dp[i][j];
//                     continue;
//                 }
//                 count += helper(s,i,j, dp);
//             }
//         }
//         return count;
//     }
    
//     int helper(string &s, int i, int j, vector<vector<int>> &dp){
//         if(i>=j) return dp[i][j]=1;
//         return dp[i][j] = s[i] == s[j] ? helper(s,i+1,j-1, dp) : 0;
//     }
        
        
        
//         TLE
//         vector<string> strSubset;
//         for(int i=0;i<s.size();i++){
//             string temp;
//             for(int j=i;j<s.size();j++){
//                 temp+=s[j];
//                 strSubset.push_back(temp);
//             }
//         }
        
//         int count=0;
//         for(auto str: strSubset){
//             if(isPalindrome(str)) count++;
//         }
//         // for(auto x: strSubset) cout<<x<<endl;
//         return count;
        
//     }
    
//     bool isPalindrome(string str){
        
//         int n = str.size();
//         for(int i=0,j=n-1;i<j; i++,j--){
//             if(str[i]!=str[j]) return 0;
//         }
//         return 1;
//     }
};