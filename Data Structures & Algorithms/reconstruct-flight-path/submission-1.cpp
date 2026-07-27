class Solution {
public:
    void dfs(string airport,unordered_map<string,priority_queue<string,vector<string>,greater<string>>>& mpp,vector<string>& ans){
        auto& it=mpp[airport];
        while(!it.empty()){
            string next=it.top();
            it.pop();
            dfs(next,mpp,ans);
        }
        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mpp;
        for(auto it:tickets){
            mpp[it[0]].push(it[1]);
        }
        vector<string> ans;
        dfs("JFK",mpp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
