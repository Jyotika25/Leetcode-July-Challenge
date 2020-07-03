	class Solution {
public:
    int arrangeCoins(int n) {
        
        
        int i=1, flag=0;
        while(n>=i){
            
            n = n - i;
            flag++;
            i++;
        }
        return flag;  
        
    }
};





