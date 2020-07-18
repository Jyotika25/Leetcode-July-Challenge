class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0) return 1;
        //even n
        double temp = myPow(x, n/2);
        
        if(n<0) x= (1/x);
        if(n%2==0) return (temp*temp);  //for even
        else return(temp*temp*x);   //for odd
    }
};
