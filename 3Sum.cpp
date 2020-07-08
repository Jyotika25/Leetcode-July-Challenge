/*
approach 1 : O(n^3) : i j k
approach 2 : i and j fixed and find k =-(i+j) :  O(n^2 * log n)
approach 3 : i fixed and j,k two sum where j+k = -(i)  : O(n^2);
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        if(n<3)
            return result;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int target = -nums[i];
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = nums[j] + nums[k];
                
                if(sum < target)  j++;
               
                else if(sum > target) k--;
                else{
                    vector<int>arrtriplet(3,0);
                    arrtriplet[0] = (nums[i]);
                    arrtriplet[1] = (nums[j]);
                    arrtriplet[2] = (nums[k]);
                    
                    result.push_back(arrtriplet);
                    
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while(j<k && nums[j] == arrtriplet[1])   j++;
                    
                     // Processing duplicates of Number 3
                     // Rolling the back pointer to the next different number backwards
                    while(j<k && nums[k] == arrtriplet[2])   k--;
                }           
            }
             // Processing duplicates of Number 1
            while(i+1< n && nums[i]==nums[i+1]) i++;
        }
        
        return result;
        
    }
};
