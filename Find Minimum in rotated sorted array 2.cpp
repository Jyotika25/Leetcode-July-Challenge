class Solution {
public:
    int findMin(vector<int>& nums) {
     //  sort(nums.begin(),nums.end());
       // return nums[0];
               int low = 0;
        int high = nums.size()-1;
        
        while(low < high)
        {
        
            int mid = (low+high)/2;

            if(nums[high] < nums[mid])
            {
                low = mid+1;
            }
            else if(nums[high] > nums[mid])
            {
                high = mid;
            }
            else 
            {
                high--;
            }
        }
        return nums[low];
    }
};
