class Solution {
    void dfs(int src, vector<int> &curr, vector<vector<int>> &graph, int dest, vector<vector<int>> &res){
        if(src == dest) {
            res.push_back((vector<int>)(curr));
            return;
        }
        for(int a : graph[src]){
            curr.push_back(a);
            dfs(a, curr, graph, dest, res);
            curr.pop_back();
           
        }
    }
    public:
     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>> res;
        vector<int> curr;
        curr.push_back(0);
        dfs(0, curr, graph, graph.size() - 1, res);
        return res;
    }
    
};
