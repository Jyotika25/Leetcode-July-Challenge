class Solution {
public:
    //caching or memorization for cases like aaaaaaa
    unordered_map<string , vector<string>> dp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s)!=dp.end())    return dp[s];
       
        vector<string> result;
        //for each string in dictionary check its presence in string
        for(string w : wordDict){
            if(s.substr(0,w.length()) == w){//if string in dictionary find in s and matches
                if(w.length() == s.length()){//then if string ends after that match
                    result.push_back(w); // push the answer
                }
                else{//if string doesnt reach end call function recursively for remaining string
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for(string t : temp)//add space and push answer
                        result.push_back(w+" "+t);
                }
            }
        }
        dp[s] = result;
        return result;
    }
};
