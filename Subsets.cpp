//iterative approach

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result = {{}};
        if(nums.size()==0)
            return result;
        
        for(int x : nums)
        {
            int n = result.size();
            for(int i=0;i<n;i++)
            {
                vector<int> r;
                 r = result[i];
                r.push_back(x);
                result.push_back(r);
            }
        }
        return result;
    }
};


//Recursive approach

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        sort(nums.begin(),nums.end());
        vector<int> sub;
        subset(nums,ans,sub,0);
        return ans;
        
        
            
    }
    void subset(vector<int>& nums, vector<vector<int>> &ans,vector<int> sub,int start)
    {
        ans.push_back(sub);
        for(int i=start;i<nums.size();i++)
        {
            sub.push_back(nums[i]);
            subset(nums,ans,sub,i+1);
            sub.pop_back();
        }
    }
};
