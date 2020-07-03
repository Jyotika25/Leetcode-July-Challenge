class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        N = N%14==0 ? 14 : N%14;
        
        //after every 14 the pattern repeates that is for 1 and 15 v have same cells output
        //there is a catch for numbers divisible by 14
        
        vector<int> cells2(8,0);
        
        while(N>0)
        {
            for(int i=1;i<cells.size()-1;i++)
            {
                //if cells[i-1] == cells[i+1]then cells2 = 1 else cells2=0
                
                cells2[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            //then v will update our cells after every day for next iteration
            cells = cells2;
            N--;    //decrement days
        }
        
        return cells;
    }
};
