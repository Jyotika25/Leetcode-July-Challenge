class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //last index
        int n = digits.size() - 1;
         
        while(n>=0)
        {
            //if last is 9 then make it 0 n go to last-1 index
            if(digits[n] == 9)
            {
                digits[n] = 0;
            }
            //if index is not 9 then add 1 to index and return array
            else 
            {
                digits[n] +=1;
                return digits;
            }
            n--;
        }
    digits.insert(digits.begin() , 1);
        return digits;
    }
};
