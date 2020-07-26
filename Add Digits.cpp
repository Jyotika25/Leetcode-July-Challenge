class Solution {
public:
    int addDigits(int num) {
      /*  // naive approach
        
        if(num<10)  return num; //base case
        
        while(num>=10){
            int sum =0;
            while(num>9){
                sum = sum + num/10;
                num = num%10;
            }
            sum = sum + num;
            num = sum;
        }
        return num;*/
        
        //digital root approach
        
        if(num == 0)    return num;
        if(num%9 == 0)  return 9;
        
        return  num%9;
    }
};
