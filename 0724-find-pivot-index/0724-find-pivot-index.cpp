class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int r_sum=0;
        int l_sum=0;
        for(int i=0;i<nums.size();i++){
            r_sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            r_sum -= nums[i];
            if(r_sum==l_sum){
                return i;
            }
            l_sum+=nums[i];
        }
        return -1;
//         vector<int> arr1;
//         vector<int> arr2;
//         int ans=-1;
//         int l_sum=0;
//         int r_sum=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             l_sum+=nums[i];
//             r_sum+=nums[n-i-1];
//             arr1.push_back(l_sum);
//             arr2.push_back(r_sum);
//         }
//         for(int i=0;i<n;i++){
//             if(arr1[i]==arr2[n-i-1]){
//                 ans=i;
//                 break;
//             }
//         }  
            
//         return ans;
    }
};