class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        int n=intervals.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev){
                ans++;
                prev=min(prev,intervals[i][1]);
            }
            else{
                prev=intervals[i][1];
            }
        }
        return ans;
    }
};
