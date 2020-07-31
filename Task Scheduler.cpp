class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      
        if(tasks.empty()) return 0;
        if(n==0) return tasks.size();
        
        int size = tasks.size();
        
        vector<int> count(26);
        int maxm=0;
        for(char c:tasks) {
            count[c-'A']++;
            maxm = max(maxm, count[c-'A']);
        }
        
        
        int total=0, required = n*(maxm-1);
        
        for(auto it:count) {
            total += min(it, maxm-1);
        }
            
        total -= (maxm-1);
        if(total>=required){
            return size;
        }
            
        return required-total+size;
     }
};



 
