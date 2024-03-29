class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int min=INT_MAX;
        int ans = 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            
            int left = i+1;
            int right=n-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(target-sum) < min){
                    min=abs(target-sum);
                    ans=sum;
                }
                
                if(sum > target ){
                    right--;
                }
                else if(sum < target )left++;
                else{
                    ans = target;
                    i=n-2;
                    break;
                }          
            
            
            
            }
        }
        
        return ans;
    }
};