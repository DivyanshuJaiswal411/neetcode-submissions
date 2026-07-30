class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=min(heights[i],heights[j])*(j-i);
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};
