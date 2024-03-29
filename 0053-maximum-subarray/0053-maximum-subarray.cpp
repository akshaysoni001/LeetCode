class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        
        int cs = 0;
        int maxSum = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            
            cs += nums[i];
            if(cs > maxSum){
                maxSum = cs;
            }            
            if(cs < 0) cs=0;
        }
        return maxSum;
        
    }
};