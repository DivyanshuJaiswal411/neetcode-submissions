class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> vec;
        for(auto it:nums1){
            vec.push_back(it);
        }
        for(auto it:nums2){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end());
        int newsize=n+m;
        if(newsize%2){
            return (double)vec[newsize/2];
        }
        int sum=vec[newsize/2]+vec[(newsize/2)-1];
        return ((double)sum)/2.0;
    }
};
