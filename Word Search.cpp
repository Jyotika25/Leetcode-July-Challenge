/*
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
    
     bool dfs(vector<vector<char>>& board ,int i ,int j ,string& word , int index){
        //if we reach at end of word
        if(index == word.length()-1)    return true;
        board[i][j] -=65;
        
        if(i>0 && board[i-1][j] == word[index+1] && dfs(board ,i-1,j,word,index+1))  return true;
        if(j>0 && board[i][j-1] == word[index+1] && dfs(board ,i,j-1,word,index+1))  return true;
        if(i<board.size()-1 && board[i+1][j] == word[index+1] && dfs(board ,i+1,j,word ,index+1))  return true;
        if(j<board[0].size()-1 && board[i][j+1] == word[index+1] && dfs(board ,i,j+1,word,index+1))  return true;
        
        board[i][j] +=65;
        return false;
    }
  
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(board[i][j] == word[0] && dfs(board,i,j,word,0))
                    return true;
        return false;
    }
};
