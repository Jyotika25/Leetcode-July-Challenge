class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int>result;
        
        map<int,int> m; //number , frequency
        
        priority_queue<pair<int,int>>pq; // frequency , number
        
        //storing number with frequency in map
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        
        //storing freuency and number on basis of frequency from the map
        for(auto i:m)
            pq.push({i.second,i.first});
        
        //till we find k frequent numbers
        for(int i=1;i<=k;i++){
            //store number from priority queue
            result.push_back(pq.top().second);
            pq.pop();
            }

        
        return result;
    }
};
