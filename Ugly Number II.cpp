class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=6)    return n;
        vector<int> dp(n);
        dp[0] = 1;
        
        int i2=0, i3=0, i5=0, index=1;
        
        while(index<n){
            int n2 = 2*dp[i2];
            int n3 = 3*dp[i3];
            int n5 = 5*dp[i5];
            
            int temp = min(n2 , min(n3,n5));
            
            dp[index++] = temp;
            
            if(temp == n2)  i2++;
            if(temp == n3)  i3++;
            if(temp == n5)  i5++;
        }
        return dp[n-1];
        
    }
};
