class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x^y;
        //find set bits only in x^y
        
        int count =0;
        while(res>0)
        {
            count += res & 1;
            res = res >> 1;
        }
        return count;
    }
};
